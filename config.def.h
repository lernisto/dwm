/* See LICENSE file for copyright and license details. */

/* appearance */
static const char *fonts[] = {
	"monospace:size=12"
};
static const char dmenufont[]       = "monospace:size=12";
static const char normbordercolor[] = "#073642";
static const char normbgcolor[]     = "#002b36";
static const char normfgcolor[]     = "#fdf6e3";
static const char selbordercolor[]  = "#2aa198";
static const char selbgcolor[]      = "#073642";
static const char selfgcolor[]      = "#fdf6e3";
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
//	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in dmenu_spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "x-terminal-emulator", NULL };
static const char *wwwcmd[]  = { "x-www-browser", NULL };
static const char *dwmcmd[] = { "dwm", NULL };

static const char *cmd_wm_status[]={"wm-status",NULL};
static const char *cmd_wm_window_list[]={"wm-window-list",NULL};
static const char *cmd_wm_menu[]={"wm-menu",NULL};
static const char *cmd_wm_launch[]={"wm-launch",NULL};
static const char *cmd_wm_launch_primary[]={"wm-launch-primary",NULL};
static const char *cmd_wm_launch_secondary[]={"wm-launch-secondary",NULL};
static const char *cmd_wm_terminal[]={"wm-terminal",NULL};
static const char *cmd_wm_explorer[]={"wm-explorer",NULL};
static const char *cmd_wm_reader[]={"wm-reader",NULL};
static const char *cmd_wm_web[]={"wm-web",NULL};
static const char *cmd_wm_mail[]={"wm-mail",NULL};
static const char *cmd_wm_media[]={"wm-media",NULL};
static const char *cmd_wm_notices[]={"wm-notices",NULL};
static const char *cmd_wm_lock[]={"wm-lock",NULL};
static const char *cmd_mm_stop[]={"mm-stop",NULL};
static const char *cmd_mm_next[]={"mm-next",NULL};
static const char *cmd_mm_prior[]={"mm-prior",NULL};
static const char *cmd_mm_play[]={"mm-play",NULL};
static const char *cmd_mm_pause[]={"mm-pause",NULL};
static const char *cmd_mm_toggle_play[]={"mm-toggle-play",NULL};
static const char *cmd_audio_mute[]={"audio-mute",NULL};
static const char *cmd_audio_unmute[]={"audio-unmute",NULL};
static const char *cmd_audio_raise[]={"audio-raise",NULL};
static const char *cmd_audio_lower[]={"audio-lower",NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },

	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      exec,           {.v = dwmcmd } },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY,                       XK_w,      spawn,          {.v = cmd_wm_web } },
	{ MODKEY,                       XK_e,      spawn,          {.v = cmd_wm_explorer } },
	{ MODKEY,                       XK_r,      spawn,          {.v = cmd_wm_reader } },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_y,      spawn,          {.v = cmd_wm_terminal } },
	{ MODKEY,                       XK_u,      spawn,          {.v = cmd_wm_terminal } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_o,      spawn,          {.v = cmd_wm_terminal } },
	{ MODKEY,                       XK_p,      dmenu_spawn,    {.v = dmenucmd } },


	{ MODKEY,                       XK_a,      spawn,          {.v = cmd_wm_terminal } },
	{ MODKEY,                       XK_s,      spawn,          {.v = cmd_wm_terminal } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_g,      spawn,          {.v = cmd_wm_terminal } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_semicolon,      spawn,          {.v = cmd_wm_terminal } },
	{ MODKEY,                       XK_apostrophe,      spawn,          {.v = cmd_wm_terminal } },
	{ MODKEY,                       XK_Return, spawn,          {.v = cmd_wm_terminal } },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },

	{ MODKEY,                       XK_z,      spawn,          {.v = cmd_wm_terminal } },
	{ MODKEY,                       XK_x,      killclient,     {0} },
	{ MODKEY,                       XK_c,      spawn,          {.v = cmd_wm_terminal } },
	{ MODKEY,                       XK_v,      spawn,          {.v = cmd_wm_terminal } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_n,      spawn,          {.v = cmd_wm_terminal } },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_slash,  spawn,          {.v = cmd_wm_terminal } },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        toggleview,     {0} },
	{ ClkTagBar,            0,              Button3,        view,           {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

