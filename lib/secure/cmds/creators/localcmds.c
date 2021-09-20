/*    /secure/cmds/creator/localcmds.c
 *    from the Foundation II LPC Library
 *    lists all commands available through add_action()
 *    created vy Descartes of Borg 950520
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    mixed *cmds;
    object ob;
    int cols;

    if( args && args != "" ) ob = find_player(args);
    if(!ob) ob = this_player();
    cols = ((int *)previous_object()->GetScreen())[0];
    cmds = (mixed *)ob->GetCommands();
    previous_object()->more(({ center("Local commands for " +
                    ob->GetName(), cols) }) +
            map(cmds, (: sprintf("%:-10s %:-40s %s",
                        $1[0], 
                        sprintf("%O", $1[2]),
                        $1[3]) :) ),
            "system");
    return 1;
}

string GetHelp(){
    return ("Syntax: localcmds\n\n"
            "Gives you a listing of all local (e.g. add_action() based) "
            "commands available to you.");
}
