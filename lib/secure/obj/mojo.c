#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
int damage1();
int damage2();
int damage3();
int damage4();
object victim;
int counter;

void create(){
    ::create();
    SetKeyName("clepius mojo");
    SetId(({"clepius mojo"}));
    SetLong(" ");
    SetInvis(1);
    set_heart_beat(1);
    counter = 0;
}

void init(){
    if(living(environment())){
        victim = environment();
    }
}


int eventMojofy(){
    int x;
    x=random(100);
    if(x < 5) damage4();
    else if(x < 20) damage3();
    else if(x < 35) damage2();
    else if(x < 50) damage1();
    return 1;
}

int damage1(){
    if( victim && victim->GetStaminaPoints() < 50) victim->AddStaminaPoints(random(5)+1);
    return 1;
}

int damage2(){
    if(victim) victim->AddHP(1);
    return 1;
}

int damage3(){
    if(victim) victim->AddHP(2);
    return 1;
}

int damage4(){
    if(victim) victim->AddHP(3);
    return 1;
}

void heart_beat(){
    if(environment() && !living(environment())) this_object()->eventDestruct();
    if(counter == 100){
        if(environment()) tell_object(environment(),"You feel the effects of the healing salve wear off.");
        this_object()->eventMove("/domains/town/room/furnace");
    }

    counter++;
    eventMojofy();
}



mixed CanGet(object ob) { return " ";}
mixed CanDrop(object ob) { return " ";}

