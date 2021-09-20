#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <magic_protection.h>

inherit LIB_SPELL;

static void create() {
    spell::create();
    SetSpell("light");
    SetRules("", "LIV");
    SetSpellType(SPELL_OTHER);
    SetRequiredMagic(20);
    SetSkills(([ "conjuring" : 5 ]));
    SetMagicCost(20, 0);
    SetDifficulty(1);
    SetMorality(10);
    SetHelp("Syntax: cast light\n"
            "Surrounds you with radiating light to see in the dark.");
}

varargs int CanCast(object who, int level, string limb, object array targets){
    object *lights = filter(all_inventory(this_player()),
            (: base_name($1) == "/obj/light" :) );
    if(sizeof(lights)){
        write("You already have a magical glow.");
        return 0;
    }
    return ::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level) {
    int intel = who->GetStatLevel("intelligence");
    int duration = intel + who->GetSkillLevel("conjuring") + who->GetSpellLevel("light");
    object mojo = new("/obj/light");

    duration += (who->GetLevel());
    duration *= 5;
    mojo->SetDuration(duration);
    mojo->eventMove(who);

    send_messages("", "A %^B_BLACK%^%^BOLD%^YELLOW%^magical glow%^RESET%^ "
            "appears around $agent_possessive_noun body.", who, 0,
            environment(who));
    return 1;
}
