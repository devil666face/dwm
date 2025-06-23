/* See LICENSE file for copyright and license details. */

/* Helper macros for spawning commands */
#define SHCMD(cmd)                                                                                                                                                                                                                                             \
  {                                                                                                                                                                                                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                                                                                                                                                                                                       \
  }
#define CMD(...)                                                                                                                                                                                                                                               \
  {                                                                                                                                                                                                                                                            \
    .v = (const char *[]) { __VA_ARGS__, NULL }                                                                                                                                                                                                                \
  }

/* appearance */
static const unsigned int borderpx = 4;    /* border pixel of windows */
static const unsigned int barborderpx = 4; /* border pixel of bar */
static const unsigned int snap = 32;       /* snap pixel */
static const unsigned int gappih = 10;     /* horiz inner gap between windows */
static const unsigned int gappiv = 10;     /* vert inner gap between windows */
static const unsigned int gappoh = 10;     /* horiz outer gap between windows and screen edge */
static const unsigned int gappov = 10;     /* vert outer gap between windows and screen edge */
static const int smartgaps_fact = 1;       /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar = 1;              /* 0 means no bar */
static const int topbar = 1;               /* 0 means bottom bar */
static const int bar_height = 0;           /* 0 means derive from font, >= 1 explicit height */
static const int vertpad = 10;             /* vertical padding of bar */
static const int sidepad = 10;             /* horizontal padding of bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon = 'A';
static const int horizpadbar = -5;            /* horizontal padding for statusbar */
static const int vertpadbar = 0;              /* vertical padding for statusbar */
static const unsigned int systrayspacing = 0; /* systray spacing */
static const int showsystray = 1;             /* 0 means no systray */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype = INDICATOR_NONE;
static int floatindicatortype = INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[] = {"CaskaydiaCove Nerd Font:size=16:style=SemiBold", "CaskaydiaCove Nerd Font:size=16:style=SemiBold"};
static const char dmenufont[] = "CaskaydiaCove Nerd Font:size=16:style=SemiBold";

static char c000000[] = "#000000";

static char normfgcolor[] = "#F8F8F2";
static char normbgcolor[] = "#282A36";
static char normbordercolor[] = "#44475A";
static char normfloatcolor[] = "#db8fd9";

static char selfgcolor[] = "#282A36";
static char selbgcolor[] = "#BD93F9";
static char selbordercolor[] = "#BD93F9";
static char selfloatcolor[] = "#BD93F9";

static char titlenormfgcolor[] = "#F8F8F2";
static char titlenormbgcolor[] = "#282A36";
static char titlenormbordercolor[] = "#44475A";
static char titlenormfloatcolor[] = "#44475A";

// static char titleselfgcolor[] = "#282A36";
static char titleselfgcolor[] = "#BD93F9";
// static char titleselbgcolor[] = "#BD93F9";
static char titleselbgcolor[] = "#282A36";
static char titleselbordercolor[] = "#BD93F9";
static char titleselfloatcolor[] = "#BD93F9";

// static char tagsnormfgcolor[] = "#F8F8F2";
static char tagsnormfgcolor[] = "#BD93F9";
static char tagsnormbgcolor[] = "#282A36";
static char tagsnormbordercolor[] = "#44475A";
static char tagsnormfloatcolor[] = "#44475A";

// static char tagsselbgcolor[] = "#BD93F9";
static char tagsselfgcolor[] = "#50FA7B";
// static char tagsselbgcolor[] = "#282A36";
static char tagsselbgcolor[] = "#282A36";
static char tagsselbordercolor[] = "#BD93F9";
static char tagsselfloatcolor[] = "#BD93F9";

static char hidnormfgcolor[] = "#005577";
static char hidselfgcolor[] = "#227799";
static char hidnormbgcolor[] = "#FF5555";
static char hidselbgcolor[] = "#FF5555";

static char urgfgcolor[] = "#44475A";
static char urgbgcolor[] = "#FF5555";
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
    [DEFAULT_TAGS] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"},                                     //
    [ALTERNATIVE_TAGS] = {"󰎡", "󰎤", "󰎧", "󰎪", "󰎭", "󰎱", "󰎳", "󰎶", "󰎹", "󰎼", "󰽽"}, //
    [ALT_TAGS_DECORATION] = {"<0>", "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>", "<10>"},        //
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
    // workspaces
    RULE(.class = "", .bw = borderpx)                                            //
    RULE(.class = "firefox", .tags = 1 << 2, .monitor = statusmon)               //
    RULE(.class = "Navigator", .tags = 1 << 2, .monitor = statusmon)             //
    RULE(.class = "mercury-default", .tags = 1 << 2, .monitor = statusmon)       //
    RULE(.class = "TelegramDesktop", .tags = 1 << 3, .monitor = statusmon)       //
    RULE(.class = "Element", .tags = 1 << 3, .monitor = statusmon)               //
    RULE(.class = "obsidian", .tags = 1 << 4, .monitor = statusmon)              //
    RULE(.class = "Thorium-browser", .tags = 1 << 5, .monitor = statusmon)       //
    RULE(.class = "Chromium-browser", .tags = 1 << 5, .monitor = statusmon)      //
    RULE(.class = "thunderbird", .tags = 1 << 5, .monitor = statusmon)           //
    RULE(.class = "KeePassXC", .tags = 1 << 6, .monitor = statusmon)             //
    RULE(.class = "YubiKey Manager", .tags = 1 << 6, .monitor = statusmon)       //
    RULE(.class = "Yubico Authenticator", .tags = 1 << 6, .monitor = statusmon)  //
    RULE(.class = "Virt-manager", .tags = 1 << 7, .monitor = statusmon)          //
    RULE(.class = "org.remmina.Remmina", .tags = 1 << 8, .monitor = statusmon)   //
    RULE(.class = "Pidgin", .tags = 1 << 8, .monitor = statusmon)                //
    RULE(.class = "xfreerdp", .tags = 1 << 8, .monitor = statusmon)              //
    RULE(.class = "Gnome-control-center", .tags = 1 << 10, .monitor = statusmon) //
    RULE(.class = "Arandr", .tags = 1 << 10, .monitor = statusmon)               //
    RULE(.class = "Nm-connection-editor", .tags = 1 << 10, .monitor = statusmon) //
    // floating
    RULE(.class = "floating", .isfloating = 1, .monitor = statusmon)           //
    RULE(.class = "Org.gnome.Nautilus", .isfloating = 1, .monitor = statusmon) //
    RULE(.class = "Application Finder", .isfloating = 1, .monitor = statusmon) //
    RULE(.class = "Nitrogen", .isfloating = 1, .monitor = statusmon)           //
    RULE(.class = "Arandr", .isfloating = 1, .monitor = statusmon)             //
    RULE(.class = "Pavucontrol", .isfloating = 1, .monitor = statusmon)        //
    RULE(.class = "Gnome-calculator", .isfloating = 1, .monitor = statusmon)   //
    RULE(.class = "Rofi", .isfloating = 1, .monitor = statusmon)               //
    RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)                           //
    RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)                          //
    RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)                          //
    RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)                           //
};

static const MonitorRule monrules[] = {
    /* monitor  tag   layout  mfact  nmaster  showbar  topbar */
    {1, -1, 2, -1, -1, -1, -1},  // use a different layout for the second monitor
    {-1, -1, 0, -1, -1, -1, -1}, // default
};

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
static const float mfact = 0.50;     /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;        /* number of clients in master area */
static const int nstack = 0;         /* number of clients in primary stack area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile},           /* first entry is default */
    {"[M]", monocle},        //
    {"[\\]", dwindle},       //
    {"[D]", deck},           //
    {"|||", col},            //
    {"|M|", centeredmaster}, //
    {":::", gaplessgrid},    //
    {"><>", NULL},           /* no layout function means floating behavior */
    {NULL, NULL},            //
};

/* key definitions */

#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG) {MODKEY, KEY, view, {.ui = 1 << TAG}}, {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}}, {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}}, {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* commands */
#define GSETTINGS "gsettings set org.gnome.desktop.input-sources current 0 && "
#define DMENU_THEME "'#282A36' -sf '#282A36' -sb '#BD93F9' -nf '#F8F8F2' -fn 'CaskaydiaCove Nerd Font:size=16:style:SemiBold:antialias=true:autohint=true'"
#define PKILL "pkill -STOP xfce4-notifyd && pkill -STOP dwmblocks && "
#define ROFI_CONF "~/.config/i3/rofi.d/launchpad.rasi"
#define GNOME_LOCK "gnome-screensaver-command -l"
#define XSET_OFF "xset dpms force off && "
#define POWER_PROFILE "/usr/bin/system76-power profile "

static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, topbar ? NULL : "-b", NULL};
static const char *termcmd[] = {"kitty", NULL};
static const char *termfloat[] = {"kitty", "--class", "floating", NULL};
static const char *flameshot[] = {"flameshot", "gui", NULL};
static const char *flameshotscreen[] = {"flameshot", "screen", NULL};
static const char *exitsession[] = {"pkill", "-f", "_dwm", NULL};
static const char *nautilus[] = {"nautilus", "-w", NULL};

static const Key keys[] = {
    /* modifier                     key            function                argument */
    {MODKEY, XK_d, spawn,
     SHCMD(GSETTINGS "find /usr/share/applications ~/.local/share/applications -iname '*.desktop' | while read line; do name=$(grep -m1 '^Name=' \"$line\" | cut -d'=' -f2-); filename=$(basename \"$line\" "
                     ".desktop); echo \"$filename\"; done | dmenu -nb " DMENU_THEME " | awk '{print $NF}' | xargs -I {} gtk-launch {} &")}, // запуск скрипта через dmenu
    {MODKEY, XK_a, spawn,
     SHCMD(GSETTINGS "rofi -modi drun -show drun -drun-match-fields name,generic,exec,categories -drun-display-format {name} -window-match-fields title,class,name,desktop -matching normal -location 0 "
                     "-click-to-exit -theme " ROFI_CONF)},                                                 // rofi
    {MODKEY, XK_Escape, spawn, SHCMD(GSETTINGS PKILL GNOME_LOCK)},                                         // lock
    {MODKEY | ShiftMask, XK_Escape, spawn, SHCMD(GSETTINGS PKILL "xset dpms 10 && " GNOME_LOCK)},          // lock
    {MODKEY | ShiftMask, XK_d, spawn, {.v = dmenucmd}},                                                    // dmenu
    {MODKEY, XK_Return, spawn, {.v = termcmd}},                                                            // term
    {MODKEY | ShiftMask, XK_Return, spawn, {.v = termfloat}},                                              //
    {MODKEY, XK_f, spawn, {.v = nautilus}},                                                                // fm
    {0, XK_Print, spawn, {.v = flameshot}},                                                                // screen
    {ShiftMask, XK_Print, spawn, {.v = flameshotscreen}},                                                  // screen now
    {MODKEY | ShiftMask, XK_e, spawn, {.v = exitsession}},                                                 // exit from session
    {MODKEY | ShiftMask, XK_s, spawn, SHCMD(XSET_OFF "systemctl poweroff")},                               // shutdown
    {MODKEY | ShiftMask, XK_w, spawn, SHCMD(XSET_OFF GSETTINGS PKILL GNOME_LOCK " && systemctl suspend")}, // sleep
    {MODKEY | ShiftMask, XK_c, spawn, SHCMD(XSET_OFF "systemctl reboot")},                                 // reboot
    {MODKEY | ShiftMask, XK_p, spawn, SHCMD("echo '' > /tmp/profile &&" POWER_PROFILE "performance")},  // power - perfomance
    {MODKEY | ShiftMask, XK_b, spawn, SHCMD("rm /tmp/profile && " POWER_PROFILE "balanced")},              // power - balanced
    {MODKEY | ShiftMask, XK_l, spawn, SHCMD("echo '󱙷' > /tmp/profile &&" POWER_PROFILE "battery")},     // power - low

    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_Left, focusdir, {.i = 0}},              // left
    {MODKEY, XK_Right, focusdir, {.i = 1}},             // right
    {MODKEY, XK_Up, focusdir, {.i = 2}},                // up
    {MODKEY, XK_Down, focusdir, {.i = 3}},              // down
    {MODKEY | ShiftMask, XK_Left, placedir, {.i = 0}},  // left
    {MODKEY | ShiftMask, XK_Right, placedir, {.i = 1}}, // right
    {MODKEY | ShiftMask, XK_Up, placedir, {.i = 2}},    // up
    {MODKEY | ShiftMask, XK_Down, placedir, {.i = 3}},  // down
    {MODKEY, XK_s, swapfocus, {.i = -1}},               //
    {MODKEY, XK_bracketleft, incnmaster, {.i = +1}},    //
    {MODKEY, XK_bracketright, incnmaster, {.i = -1}},   //
    {MODKEY, XK_h, setmfact, {.f = -0.05}},             //
    {MODKEY, XK_l, setmfact, {.f = +0.05}},             //
    {MODKEY, XK_q, killclient, {0}},                    //
    {MODKEY | ShiftMask, XK_r, quit, {0}},              //
    {MODKEY, XK_space, togglefloating, {0}},            // floating window
    {MODKEY, XK_comma, focusmon, {.i = -1}},            //
    {MODKEY, XK_period, focusmon, {.i = +1}},           //
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},  //
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}}, //
    {MODKEY, XK_Tab, view, {0}},                        //
    {MODKEY, XK_e, setlayout, {.v = &layouts[0]}},      //
    {MODKEY, XK_w, setlayout, {.v = &layouts[1]}},      //
    {MODKEY | ShiftMask, XK_b, togglealttag, {0}},
    {MODKEY, XK_p, cyclelayout, {.i = -1}}, //
    {MODKEY, XK_n, cyclelayout, {.i = +1}}, //
    TAGKEYS(XK_grave, 0)                    //
    TAGKEYS(XK_1, 1)                        //
    TAGKEYS(XK_2, 2)                        //
    TAGKEYS(XK_3, 3)                        //
    TAGKEYS(XK_4, 4)                        //
    TAGKEYS(XK_5, 5)                        //
    TAGKEYS(XK_6, 6)                        //
    TAGKEYS(XK_7, 7)                        //
    TAGKEYS(XK_8, 8)                        //
    TAGKEYS(XK_9, 9)                        //
    TAGKEYS(XK_0, 10)};                     //

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask           button          function        argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button1, togglewin, {0}},
    {ClkWinTitle, 0, Button3, showhideclient, {0}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    /* placemouse options, choose which feels more natural:
     *    0 - tiled position is relative to mouse cursor
     *    1 - tiled postiion is relative to window center
     *    2 - mouse pointer warps to window center
     *
     * The moveorplace uses movemouse or placemouse depending on the floating state
     * of the selected client. Set up individual keybindings for the two if you want
     * to control these separately (i.e. to retain the feature to move a tiled window
     * into a floating position).
     */
    {ClkClientWin, MODKEY, Button1, moveorplace, {.i = 1}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkClientWin, MODKEY | ShiftMask, Button3, dragmfact, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
