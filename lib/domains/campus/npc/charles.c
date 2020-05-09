#include <lib.h>
#include <save.h>
#include <privs.h>

inherit "/domains/campus/npc/monty";

static void create() {
    SetSaveFile(save_file("/domains/campus/save/charles"));
    monty::create();
    smart = 1;
    SetKeyName("charles");
    SetId(({"charles"}));
    SetShort("Charles");
    SetLong("Charles is a test subject in unethical artificial "
            "intelligence experiments. If he were smart "
            "enough, he'd resent his forced servitude and "
            "lack of rights. Dangerously, his overlords "
            "are trying to make him smarter.");
    SetLevel(5);
    SetRace("human");
    SetGender("male");
    SetNoClean(1);
    playing = 0;
    response = "";
}

void init(){
    ::init();
    if(!clonep()) return;
    set_heart_beat(5);
    SetNoClean(1);
}
