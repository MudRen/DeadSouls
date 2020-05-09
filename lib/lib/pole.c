/*    /lib/pole.c
 *    from the Dead Souls Object Library
 *    inheritable fishing functions, must also inherit item along the way
 *    created by Descartes of Borg 951009
 */

#include <lib.h>
#include "include/pole.h"

inherit LIB_BAIT;

static private int PoleStrength, CatchChance;

static void create(){
    string *bait_save = bait::GetSave();
    PoleStrength = 0;
    CatchChance = 0;
    AddSave( ({ "PoleStrength", "CatchChance" }) +  bait_save );
}

mixed direct_cast_obj(){
    if( environment() != this_player() )
        return "#You must have it to cast it.";
    return 1;
}

mixed direct_fish_with_obj(){
    mixed err;

    if( environment() != this_player() )
        return "#You must have it to fish with it!";
    if( (err = CanCast(this_player())) != 1 ) return err;
    return 1;
}

int eventBreak(){
    SetBroken(1);
    return 1;
}

mixed CanCast(object who){
    if( GetBroken() )
        return "You cannot cast a broken " + strip_article(GetShort()) + "!";
    else return 1;
}

mixed eventCatch(object who, string fish){
    int mass;

    SetBait(0);
    mass = fish->GetMass();
    if( mass > PoleStrength && eventBreak() ){
        message("my_action", "Just as you notice " + fish->GetShort() +
                " on " + GetShort() + ", it breaks "
                "and you lose your catch!", who);
        message("my_action", possessive_noun(who) + " " +
                strip_article(GetShort()) + " breaks as " +
                nominative(who) + " tries to land " + fish->GetShort()+
                "!", environment(who), ({ who }));
        return 0;
    }
    PoleStrength -= (mass/10) + 1;
    if( PoleStrength < 1 ) PoleStrength = 0;
    if( !(fish->eventCatch(who, this_object()))) return 0;
    if( !(who->CanCarry(mass)) ){
        message("my_action", "For a fleeting moment, you notice " +
                fish->GetShort() + " on your " +
                strip_article(GetShort()) + ", but then it is lost.",
                who);
        message("other_action", who->GetName() + " loses a catch.",
                environment(who), ({ who }));
        return 0;
    }
    return 1;
}

int eventFish(object who){
    if( who->GetSkillLevel("fishing") >= random(5) )
        return GetChance() + GetBait();
    else return 0;
}


int SetChance(int x){ return (CatchChance =x); }

mixed GetProperty(string foo);

int GetChance(){ return CatchChance + GetProperty("blessed"); }

int SetStrength(int x){ return (PoleStrength = x);  }

int GetStrength(){ return PoleStrength; }

/* virtual functions */

mixed AddSave(mixed *vars){ return ({}); }
