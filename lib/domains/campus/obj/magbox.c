/*    /domains/Examples/etc/bag.c
 *    from the Dead Souls LPC Library
 *    a sample bag object
 *    created by Descartes of Borg 950529
 */

#include <lib.h>

inherit LIB_STORAGE;

void create() {
    ::create();
    SetKeyName("magbox");
    SetId( ({ "box","magentabox" , "magbox" , "mbox" }) );
    SetAdjectives( ({ "small", "plastic","magenta", "a" }) );
    SetShort("a small, %^MAGENTA%^magenta%^RESET%^ plastic box");
    SetLong("It is a simple plastic box used to hold things. It is %^MAGENTA%^magenta%^RESET%^, and it has a cute Virtual Campus "+
            "logo on it.");
    SetMass(274);
    SetDollarCost(1);
    SetMaxCarry(100);
    SetCanClose(1);
    SetClosed(0);
    //    SetPreventPut("You cannot put this in there!");
}
void init(){
    ::init();
}
