// Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    {"󱊣", "echo \"$(cat /sys/class/power_supply/BAT0/capacity)%\"", 15, 0},
    // {"󰍛 ", "top -bn1 | grep 'Cpu(s)' | sed 's/.*, *\\([0-9.]*\\)%* id.*/\\1/' | awk '{print $1\"%\"}'", 5, 0},
    // {"󰋊 ", "df -h / | awk 'NR==2 {print $4}'", 60, 0},
    // {" ", "free -h | awk '/Mem:/ {print $3}'", 5, 0},
    // {"", "cat /sys/class/thermal/thermal_zone0/temp | awk '{print $1/1000 \"°C\"}'", 5, 0},
    {"󰃠 ", "echo \"$(( ($(cat /sys/class/backlight/*/brightness) - 193) * 100 / (19393 - 193) ))%\"", 1, 0},
    {"", "cat /tmp/profile", 1, 0},
    {"", "amixer get Master | awk -F'[][]' '/Left:/ {if ($4 == \"off\") print \"󰖁\"; else print \" \"$2}'", 1, 10},
    {"󰸗 ", "date '+%a %d.%m.%Y'", 60, 0},
    {"", "date '+%H:%M:%S'", 1, 0},
    {"", "echo $(case \"$(xset -q|grep LED|awk '{print $10}')\" in \"00000000\") echo \"en\" ;; \"00001000\") echo \"ru\" ;; *) echo \"⬆️\" ;; esac)", 1, 0},
};

static char delim[] = " ";
// static char delim[] = "\0";
static unsigned int delimLen = 7;
