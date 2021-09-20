/*    /cmds/players/customize.c
 *    from the Dead Souls Mud Library
 *    customize
 *    customize STAT AMOUNT
 *    created by Descartes of Borg 950113
 */

#include <lib.h>
#include <message_class.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    mixed tmp;
    string stat;
    int amt;

    if( !args || args == "" ) {
        amt = this_player()->GetCustomStats();
        this_player()->eventPrint("You have " + amt + " points left to "
                "spend on stats.", MSG_SYSTEM);
        return 1;
    }
    amt = to_int((tmp = explode(args, " "))[<1]);
    if( sizeof(tmp) == 1 ) return "Customize which stat how much?";
    stat = implode(tmp[0..<2], " ");
    tmp = this_player()->eventCustomizeStat(stat, amt);
    if( stringp(tmp) ) return tmp;
    if( !tmp ) return "Failed to raise stat.";
    this_player()->eventPrint("Your " + stat + " is now at " + tmp +
            ", and you have " +
            this_player()->GetCustomStats() +
            " points left to spend.", MSG_SYSTEM);
    return 1;
}

string GetHelp(){
    return ("Syntax: customize [STAT AMOUNT]\n\n"
            "Allows you to spend customization points to boost the "
            "stats with which you were born. "
            "Using this command without arguments tells you how many "
            "points you have left to spend.\n"
            "Example: customize strength 5"
            "\nNOTE: Once spent, that's it. You will not receive "
            "more customization points.\n"
            "See also: stats, stat, skills, deviation");
}
