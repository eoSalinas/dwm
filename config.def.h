/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */

static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 20;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */

static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=10", "monospace:size=10", };
static const char dmenufont[]       = "monospace:size=10";

// Kanagawa Color Palette (if xrdb is not loaded)
static char normbgcolor[]       = "#1F1F28"; // Dark background (unfocused)
static char normbordercolor[]   = "#333344"; // Border (unfocused)
static char normfgcolor[]       = "#DCD7BA"; // Light beige foreground (text)
static char selfgcolor[]        = "#DCD7BA"; // Light beige foreground (focused)
static char selbordercolor[]    = "#7E9CD8"; // Soft blue border (focused)
static char selbgcolor[]        = "#7E9CD8"; // Soft blue background (focused)

static char *colors[][3]      = {
    [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
    [SchemeSel]  = { selbgcolor,  selfgcolor,  selbordercolor  },

    [SchemeStatus]  = { normfgcolor, normbgcolor,  normbgcolor  }, // Statusbar right
    [SchemeTagsSel]  = { normfgcolor, normbgcolor,  normbgcolor  }, // Tagbar left selected
    [SchemeTagsNorm]  = { selbordercolor, normbgcolor,  normbgcolor  }, // Tagbar left unselected
    [SchemeInfoSel]  = { normfgcolor, normbgcolor,  normbgcolor  }, // infobar middle  selected
    [SchemeInfoNorm]  = { normfgcolor, normbgcolor,  normbgcolor  }, // infobar middle
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	{ NULL, NULL, NULL, 0, 0, -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    { "󰇥",      tile },    /* first entry is default */
	{ "󰯉",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };

static const char *termcmd[] = { "st", NULL };
static const char *yazicmd[] = { "st", "-e", "yazi", NULL };

static const Key keys[] = {
	{ MODKEY|ShiftMask, XK_BackSpace, quit, {0} }, // quit dwm :(
	{ MODKEY, XK_F5, xrdb, {.v = NULL } }, // reload colors

    // navigation (tag)
	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3)
	TAGKEYS(XK_5, 4)
	TAGKEYS(XK_6, 5)
	TAGKEYS(XK_7, 6)
	TAGKEYS(XK_8, 7)
	TAGKEYS(XK_9, 8)

	{ MODKEY, XK_Tab, view, {0} }, // like alt-tab

    // layouts
	{ MODKEY, XK_t, setlayout, {.v = &layouts[0]} }, // tiled (default) 
	{ MODKEY, XK_f, setlayout, {.v = &layouts[1]} }, // floating
	{ MODKEY, XK_m, setlayout, {.v = &layouts[2]} }, // monocle

	{ MODKEY|ShiftMask, XK_h, setmfact, {.f = -0.05} },
	{ MODKEY|ShiftMask, XK_l, setmfact, {.f = +0.05} },
	{ MODKEY|ShiftMask, XK_0, togglegaps, {0} }, // toggle vanity gaps

	{ MODKEY, XK_i, incnmaster, {.i = +1 } }, // only tiled layout
	{ MODKEY, XK_d, incnmaster, {.i = -1 } }, // only tiled layout

	{ MODKEY, XK_b, togglebar, {0} },

    // navigation (view)
	{ MODKEY, XK_j, focusstack, {.i = +1 } },
	{ MODKEY, XK_k, focusstack, {.i = -1 } },
	{ MODKEY, XK_z, zoom, {0} },

	{ MODKEY, XK_q, killclient, {0} },

    // application/script bindings
	{ MODKEY, XK_Return, spawn, {.v = termcmd } },
    { MODKEY, XK_space, spawn, {.v = dmenucmd } },
    { MODKEY, XK_e, spawn, {.v = yazicmd} },

    { MODKEY|ShiftMask, XK_w, spawn, SHCMD("$XDG_CONFIG_HOME/scripts/set-wallpaper") },

    // multi-monitor control
	{ MODKEY, XK_bracketleft, focusmon, {.i = +1 } },
	{ MODKEY|ShiftMask, XK_bracketleft, tagmon, {.i = +1 } },
	{ MODKEY, XK_bracketright, focusmon, {.i = -1 } },
	{ MODKEY|ShiftMask, XK_bracketright, tagmon, {.i = -1 } },

    // volume control
	{ 0, XK_F1, spawn, SHCMD("$XDG_CONFIG_HOME/scripts/volume mute") },
    { 0, XK_F2, spawn, SHCMD("$XDG_CONFIG_HOME/scripts/volume down") },
	{ 0, XK_F3, spawn, SHCMD("$XDG_CONFIG_HOME/scripts/volume up") },

    // brightness control
	{ 0, XK_F11, spawn, SHCMD("$XDG_CONFIG_HOME/scripts/screenlight down") },
    { 0, XK_F12, spawn, SHCMD("$XDG_CONFIG_HOME/scripts/screenlight up") },
};

/* button definitions */
static const Button buttons[] = {
	{ ClkClientWin, MODKEY, Button1, movemouse, {0} },
	{ ClkClientWin, MODKEY, Button3, resizemouse, {0} },
};
