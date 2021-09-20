/*    /lib/mayor.c
 *    From the Dead Souls Object Library
 *    Allows players to change their residence on the mud
 *    Created by Descartes of Borg 961019
 *    Version: @(#) mayor.c 1.3@(#)
 *    Last modified: 96/10/20
 */

#include <lib.h>

inherit LIB_SENTIENT;

static void EvaluateCitizenshipRequest();

int Tax = 0;
string LocalCurrency = "gold";

static void create(){
    sentient::create();
    SetRequestResponses(([ "citizenship" : (: EvaluateCitizenshipRequest :),
                "help" : (: this_object()->eventForce("say You can request "
                        "citizenship from me.") :) ]));
}

mixed CanRequestCitizenship(object who){
    if( Tax > 0 ){
        int cost = (Tax);

        if( who->GetCurrency(LocalCurrency) < cost ){
            this_object()->eventForce("say I'm sorry, but we have a new citizen tax of " + Tax + " " +
                    LocalCurrency + ".");
            return 0;
        }
    }
    if( who->GetTown() == GetTown() ){
        return "You are already a citizen of " + GetTown() + ".";
    }
    return 1;
}

mixed eventRequestCitizenship(object who){
    object array homies = filter(users(), (: $1->GetTown() == GetTown() :));

    homies->eventPrint(who->GetName() + " is now a citizen of " + GetTown() +
            ".");
    who->SetTown(GetTown());
    who->eventPrint("You are now a citizen of " + GetTown() + ".");
    if( Tax > 0 ){
        int cost = Tax;

        who->AddCurrency(LocalCurrency, -cost);
        this_object()->AddCurrency(LocalCurrency, cost);
        this_object()->eventForce("say Congratulations, citizen!");
    }
    return 1;
}

static void EvaluateCitizenshipRequest(){
    mixed tmp = CanRequestCitizenship(this_player());

    if( tmp != 1 ){
        if( !tmp  || tmp == 0 ){
            this_object()->eventForce("say Your request is denied.");
        }
        else {
            this_player()->eventPrint(tmp);
        }
        return;
    }
    eventRequestCitizenship(this_player());
}

string GetLocalCurrency(){
    return LocalCurrency;
}

static string SetLocalCurrency(string str){
    return (LocalCurrency = str);
}

int GetTax(){
    return Tax;
}

static int SetTax(int x){
    return (Tax = x);
}
