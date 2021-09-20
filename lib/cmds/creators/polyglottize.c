#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string str) {
    object target;

    if(!str || str == "") str = "me";

    if(str == "me") str = this_player()->GetKeyName();
    if(!target = present(str, environment(this_player()))){
        write("They're not here.");
        return 1;
    }
    if(!living(target)) {
        write("That's not a living thing.");
        return 1;
    }
    if(creatorp(target) && !archp(this_player()) &&
            target != this_player()){
        write("That's impolite.");
        tell_player(target,capitalize(this_player()->GetKeyName())+
                " just tried to polyglottize you.");
        return 1;
    }

    target->SetPolyglot(1);
    if(target == this_player()) str = "yourself";
    else str = capitalize(str);
    write("You polyglottize "+str+".");
    if(target != this_player()) 
        tell_object(target, capitalize(this_player()->GetKeyName())+" polyglottizes you.");
    return 1;
}

string GetHelp() {
    return ("Syntax: polyglottize <target>\n\n"
            "Make the target able to understand all languages.");
}                                                    
