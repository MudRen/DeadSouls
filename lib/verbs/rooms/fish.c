/*    /verbs/rooms/fish.c
 *    from the Dead Souls Mud Library
 *    fish with OBJ
 *    created by Descartes of Borg 951016
 */

#include <lib.h>
#include "include/fish.h"

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("fish");
    SetRules("with OBJ");
    SetErrorMessage("Fish with what?");
    SetHelp("Syntax: fish with <OBJ>\n\n"
            "Starts you fishing so long as OBJ is something you can fish "
            "with and you are in a place that allows fishing.\n"
            "See also: stop");
}

mixed can_fish_with_obj(){
    object env;
    mixed err;
    if( !(env = environment(this_player())) ) return 0;
    err = env->CanCast(this_player());
    if( err == 1 ) return this_player()->CanManipulate();
    else if( !err ) return "It doesn't look like there is much fishing here.";
    else return err;
}

mixed do_fish_with_obj(object ob){ 
    object env;
    mixed err;
    if( !ob || !(env = environment(this_player())) ) return 0;
    if( err = env->eventCast(this_player(), ob) ) return err;
}
