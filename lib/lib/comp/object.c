/*    /lib/comp/object.c
 *    From the Dead Souls LPC Library
 *    Object inherited by all tangible objects (ones with environments)
 *    Created by Descartes of Borg 940211
 *    Version: @(#) object.c 1.10@(#)
 *    Last Modified: 96/12/22
 */

#include <lib.h>

//inherit LIB_SHADOW_HOOK;
inherit LIB_CLEAN;
inherit LIB_DESCRIPTION;
inherit LIB_ID;
inherit LIB_LISTEN;
inherit LIB_LOOK;
inherit LIB_PROPERTIES;
inherit LIB_RADIANCE;
inherit LIB_SMELL;
inherit LIB_TOUCH;
inherit LIB_SHOOT;

mixed CanDest(){
    if(environment() != environment(this_player()) &&
            environment() != this_player())
        return "#That's not accessible to you.";
    else return 1;
}

mixed indirect_dest_obj(){ return CanDest(); }
mixed direct_dest_obj(){ return CanDest(); }

/* ************************ object.c events ********************* */
static int Destruct(){
    object env;
    int x;

    if( env = environment() ){
        env->eventReleaseObject(this_object());
        x = clean::Destruct();
        if( !x ){
            env->eventReceiveObject(this_object());
        }
        return x;
    }
    else return clean::Destruct();
}

/* ******************* object.c driver applies **************** */
static void create(){
    parse_init();
}
