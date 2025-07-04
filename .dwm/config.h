/* appearance */
static const unsigned int borderpx = 3; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const unsigned int gappih = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv = 10;  /* vert inner gap between windows */
static const unsigned int gappoh = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact = 0;    /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar = 1;           /* 0 means no bar */
static const int topbar = 1;            /* 0 means bottom bar */

/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon = 'A';
static const unsigned int systrayspacing = 2; /* systray spacing */
static const int showsystray = 0;             /* 0 means no systray */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype = INDICATOR_NONE;
static int floatindicatortype = INDICATOR_TOP_LEFT_SQUARE;

static const char *fonts[] = {"CaskaydiaCove Nerd Font:size=15:style=SemiBold", "CaskaydiaCove Nerd Font:size=15:style=SemiBold"};
static const char dmenufont[] = "CaskaydiaCove Nerd Font:size=15:style=SemiBold";

static char c000000[] = "#000000";

static char normfgcolor[] = "#ebdbb2";
static char normbgcolor[] = "#282828";
static char normbordercolor[] = "#3c3836";
static char normfloatcolor[] = "#db8fd9";

static char selfgcolor[] = "#fbf1c7";
static char selbgcolor[] = "#d65d0e";
static char selbordercolor[] = "#d65d0e";
static char selfloatcolor[] = "#d65d0e";

static char titlenormfgcolor[] = "#ebdbb2";
static char titlenormbgcolor[] = "#282828";
static char titlenormbordercolor[] = "#3c3836";
static char titlenormfloatcolor[] = "#3c3836";

static char titleselfgcolor[] = "#fbf1c7";
static char titleselbgcolor[] = "#d65d0e";
static char titleselbordercolor[] = "#d65d0e";
static char titleselfloatcolor[] = "#d65d0e";

static char tagsnormfgcolor[] = "#ebdbb2";
static char tagsnormbgcolor[] = "#282828";
static char tagsnormbordercolor[] = "#3c3836";
static char tagsnormfloatcolor[] = "#3c3836";

static char tagsselfgcolor[] = "#fbf1c7";
static char tagsselbgcolor[] = "#d65d0e";
static char tagsselbordercolor[] = "#d65d0e";
static char tagsselfloatcolor[] = "#d65d0e";

static char hidnormfgcolor[] = "#005577";
static char hidselfgcolor[] = "#227799";
static char hidnormbgcolor[] = "#222222";
static char hidselbgcolor[] = "#222222";

static char urgfgcolor[] = "#bbbbbb";
static char urgbgcolor[] = "#222222";
static char urgbordercolor[] = "#ff0000";
static char urgfloatcolor[] = "#db8fd9";

static char *colors[][ColCount] = {
    /*                       fg                bg                border                float */
    [SchemeNorm] = {normfgcolor, normbgcolor, normbordercolor, normfloatcolor},
    [SchemeSel] = {selfgcolor, selbgcolor, selbordercolor, selfloatcolor},
    [SchemeTitleNorm] = {titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor},
    [SchemeTitleSel] = {titleselfgcolor, titleselbgcolor, titleselbordercolor, titleselfloatcolor},
    [SchemeTagsNorm] = {tagsnormfgcolor, tagsnormbgcolor, tagsnormbordercolor, tagsnormfloatcolor},
    [SchemeTagsSel] = {tagsselfgcolor, tagsselbgcolor, tagsselbordercolor, tagsselfloatcolor},
    [SchemeHidNorm] = {hidnormfgcolor, hidnormbgcolor, c000000, c000000},
    [SchemeHidSel] = {hidselfgcolor, hidselbgcolor, c000000, c000000},
    [SchemeUrg] = {urgfgcolor, urgbgcolor, urgbordercolor, urgfloatcolor},
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */

static char *tagicons[][NUMTAGS] = {
    [DEFAULT_TAGS] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"},
    [ALTERNATIVE_TAGS] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"},
    [ALT_TAGS_DECORATION] = {"<0>", "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>", "<10>"},
};

/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     *	WM_WINDOW_ROLE(STRING) = role
     *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
     */
    RULE(.wintype = WTYPE "DIALOG", .isfloating = 1) RULE(.wintype = WTYPE "UTILITY", .isfloating = 1) RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1) RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)};

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
    /* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
    {-1, 0, BAR_ALIGN_LEFT, width_tags, draw_tags, click_tags, hover_tags, "tags"},
    {0, 0, BAR_ALIGN_RIGHT, width_systray, draw_systray, click_systray, NULL, "systray"},
    {-1, 0, BAR_ALIGN_LEFT, width_ltsymbol, draw_ltsymbol, click_ltsymbol, NULL, "layout"},
    {statusmon, 0, BAR_ALIGN_RIGHT, width_status, draw_status, click_status, NULL, "status"},
    {-1, 0, BAR_ALIGN_NONE, width_awesomebar, draw_awesomebar, click_awesomebar, NULL, "awesomebar"},
};

/* layout(s) */
static const float mfact = 0.5;      /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;        /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

#include <X11/XF86keysym.h>

#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG) {MODKEY, KEY, view, {.ui = 1 << TAG}}, {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}}, {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}}, {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},
#define SHCMD(cmd)                                                                                                                                                                                                                                             \
  {                                                                                                                                                                                                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                                                                                                                                                                                                       \
  }

static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */

static const char *dmenucmd[] = {"dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL};
static const char *termcmd[] = {"kitty", NULL};
static const char *flameshot[] = {"flameshot", "gui", NULL};
static const char *flameshotscreen[] = {"flameshot", "screen", NULL};
static const char *exitsession[] = {"pkill", "-f", "_dwm", NULL};
static const char *nautilus[] = {"nautilus", "-w", NULL};

static const Key keys[] = {
    /* modifier                     key            function                argument */
    {MODKEY, XK_Return, spawn, {.v = termcmd}},                // Term
    {MODKEY, XK_q, killclient, {0}},                           // Close current window
    {MODKEY | ShiftMask, XK_r, quit, {0}},                     // Restart dwm
    {MODKEY | ShiftMask, XK_e, spawn, {.v = exitsession}},     // Exit from session
    {MODKEY, XK_d, spawn, {.v = dmenucmd}},                    // Dmenu
    {MODKEY, XK_b, togglebar, {0}},                            // Show/close bar
    {MODKEY, XK_e, setlayout, {.v = &layouts[0]}},             // Tiling lay
    {MODKEY | ShiftMask, XK_f, setlayout, {.v = &layouts[1]}}, // Floaling lay
    {MODKEY, XK_w, setlayout, {.v = &layouts[2]}},             // Tab lay
    {MODKEY, XK_Left, focusstack, {.i = -1}},                  // Select prev window
    {MODKEY, XK_Down, focusstack, {.i = +1}},                  // Select next window
    {MODKEY, XK_Up, focusstack, {.i = -1}},                    // Select prev window
    {MODKEY, XK_Right, focusstack, {.i = +1}},                 // Select next window
    {MODKEY | ShiftMask, XK_Left, movemouse, {.i = -1}},
    {MODKEY | ShiftMask, XK_Down, movemouse, {.i = 1}},
    {MODKEY | ShiftMask, XK_Up, movemouse, {.i = -1}},
    {MODKEY | ShiftMask, XK_Right, movemouse, {.i = 1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},             // Resize to right
    {MODKEY, XK_l, setmfact, {.f = +0.05}},             // Resize to left
    {MODKEY, XK_j, incnmaster, {.i = +1}},              // Move lay
    {MODKEY, XK_k, incnmaster, {.i = -1}},              // Move lay
    {MODKEY, XK_Tab, view, {0}},                        // Go to last open workspace
    {MODKEY | ShiftMask, XK_z, showhideclient, {0}},    // Hide window
    {MODKEY, XK_space, togglefloating, {0}},            // Floating this window
    {MODKEY, XK_comma, focusmon, {.i = -1}},            // Prev monitor
    {MODKEY, XK_period, focusmon, {.i = +1}},           // Next monitor
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},  // Window on prev mon
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}}, // Window on next mon

    {0, XK_Print, spawn, {.v = flameshot}},
    {MODKEY, XK_f, spawn, {.v = nautilus}},
    {ShiftMask, XK_Print, spawn, {.v = flameshotscreen}},

    TAGKEYS(XK_grave, 0) TAGKEYS(XK_1, 1) TAGKEYS(XK_2, 2) TAGKEYS(XK_3, 3) TAGKEYS(XK_4, 4) TAGKEYS(XK_5, 5) TAGKEYS(XK_6, 6) TAGKEYS(XK_7, 7) TAGKEYS(XK_8, 8) TAGKEYS(XK_9, 9) TAGKEYS(XK_0, 10)};

// Gaps
// {MODKEY | Mod4Mask, XK_u, incrgaps, {.i = +1}},
// {MODKEY | Mod4Mask | ShiftMask, XK_u, incrgaps, {.i = -1}},
// {MODKEY | Mod4Mask, XK_i, incrigaps, {.i = +1}},
// {MODKEY | Mod4Mask | ShiftMask, XK_i, incrigaps, {.i = -1}},

// Don't know
// {MODKEY | ShiftMask, XK_Return, zoom, {0}},
// {MODKEY, XK_0, view, {.ui = ~0}}, // Select all tags
// {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}}, // Set this window on all tags
// {MODKEY, XK_space, setlayout, {0}},

// {MODKEY | Mod4Mask, XK_o, incrogaps, {.i = +1}},
// {MODKEY | Mod4Mask | ShiftMask, XK_o, incrogaps, {.i = -1}},
// {MODKEY | Mod4Mask, XK_6, incrihgaps, {.i = +1}},
// {MODKEY | Mod4Mask | ShiftMask, XK_6, incrihgaps, {.i = -1}},
// {MODKEY | Mod4Mask, XK_7, incrivgaps, {.i = +1}},
// {MODKEY | Mod4Mask | ShiftMask, XK_7, incrivgaps, {.i = -1}},
// {MODKEY | Mod4Mask, XK_8, incrohgaps, {.i = +1}},
// {MODKEY | Mod4Mask | ShiftMask, XK_8, incrohgaps, {.i = -1}},
// {MODKEY | Mod4Mask, XK_9, incrovgaps, {.i = +1}},
// {MODKEY | Mod4Mask | ShiftMask, XK_9, incrovgaps, {.i = -1}},
// {MODKEY | Mod4Mask, XK_0, togglegaps, {0}},
// {MODKEY | Mod4Mask | ShiftMask, XK_0, defaultgaps, {0}},

/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask           button          function        argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button1, togglewin, {0}},
    {ClkWinTitle, 0, Button3, showhideclient, {0}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
