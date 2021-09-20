/*    /domains/Examples/etc/door.c
 *    from the Dead Souls LPC Library
 *    an example door object connecting doorroom1.c and doorroom2.c
 *    created by Descartes of Borg 950411
 */

#include <lib.h>

inherit LIB_DOOR;

static void create() {
    door::create();
    SetSide("east", ([ "id" : ({ "east door" , "second door" }),
                "short" : "a steel door leading east",
                "long" : "This is an imposing, large steel door leading east, out of the arena.",
                "lockable" : 0 ]) );
    SetSide("west", ([ "id" : ({ "west door" ,"door" }),
                "short" : "a steel door leading west",
                "long" : "This is an imposing, large steel door leading west into the main arena.",
                "lockable" : 0 ]) );
    SetClosed(0);
}
