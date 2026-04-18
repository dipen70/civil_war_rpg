// ============================================================
//  DialogueManager.cpp  —  Dialogue Engine Implementation
//  Contains ALL story content: scenes, NPC lines, choices,
//  and consequences for both the Spy and Rebel Leader paths.
// ============================================================
#include "DialogueManager.h"
#include <iostream>
#include <limits>

// ─── Constructor: build both dialogue trees ───────────────
DialogueManager::DialogueManager() {
    buildSpyDialogues();
    buildRebelDialogues();
}

// ══════════════════════════════════════════════════════════
//  SPY PATH — 6 Scenes
//  Player = Agent Thomas "Tom" Harrison (cover: Elias Webb)
//  NPC    = Colonel Whitmore (secretly also a Union agent)
// ══════════════════════════════════════════════════════════
void DialogueManager::buildSpyDialogues() {

    // ── Scene 1: Captured and brought before the Colonel ──
    spyDialogues.push_back({
        "Virginia, 1863. You have been captured near a Confederate supply depot.\n"
        "A Confederate soldier drags you into a dimly-lit barn. Colonel Whitmore\n"
        "sits at a rough-hewn table, studying you with cold, measured eyes.\n"
        "He speaks slowly, each word deliberate as a rifle shot.",

        "Who are you, and what business brings a man like you this close to our\n"
        "supply lines?",

        {
            {"I am Elias Webb, a dry-goods merchant out of Cincinnati.\n"
             "   I lost my route and found myself here by accident.",
             true,
             "Whitmore narrows his eyes, but nods slowly. 'Cincinnati, you say.\n"
             "   A long way from home. We shall see.' He signals a guard to wait outside.",
             10},

            {"I am a courier for the Union Army and I demand to be released\n"
             "   under the rules of war!",
             false,
             "Whitmore stands instantly. 'Seize him — this man is a Union spy!\n"
             "   Take him to the stockade.' Your cover is shattered.",
             60},

            {"I have no obligation to answer questions from Confederate rebels.",
             false,
             "Whitmore smiles thinly. 'Bold. And suspicious. Add fifteen lashes\n"
             "   until he finds his tongue.' Guards advance on you.",
             45},

            {"I... I am nobody. Just a traveler. Please, I mean no harm.",
             false,
             "Whitmore slams the table. 'Cowardly AND evasive. That combination\n"
             "   usually means guilty of something. Strip his pack — search everything.'",
             25}
        }
    });

    // ── Scene 2: Your satchel is searched ─────────────────
    spyDialogues.push_back({
        "A soldier empties your satchel onto the table. Cloth samples, a ledger\n"
        "of prices, and — your stomach drops — a small folded map fall out.\n"
        "Whitmore picks up the map slowly and unfolds it.",

        "This map shows Confederate troop positions. Merchants do not carry\n"
        "such things. Explain yourself, Mr. Webb.",

        {
            {"I purchased that map from a peddler in Lexington for three dollars.\n"
             "   Knowing troop positions keeps me off dangerous roads.",
             true,
             "Whitmore studies you. 'A merchant who values his skin. Plausible.\n"
             "   But I will keep the map.' He sets it aside carefully.",
             5},

            {"I have never seen that map before! Someone must have planted it!",
             false,
             "Whitmore almost laughs. 'Planted it. In a locked satchel on your\n"
             "   back. That is the most creative lie I have heard this month.\n"
             "   Chain him.' Suspicion skyrockets.",
             40},

            {"All right — I bought it to sell information to the highest bidder.\n"
             "   I am not loyal to either side, Colonel.",
             false,
             "Whitmore stares at you for a long moment. 'A mercenary. Even more\n"
             "   dangerous than a spy. Put him with the others awaiting trial.'",
             30},

            {"I am a man of commerce, Colonel. Information about roads and camps\n"
             "   helps me avoid trouble and deliver goods on schedule.",
             true,
             "Whitmore sets the map down. 'That... is a reasonable answer for a\n"
             "   careful businessman. But you will stay in camp until I verify your\n"
             "   story.' He waves the guard to ease back.",
             8}
        }
    });

    // ── Scene 3: Whitmore probes your knowledge ────────────
    spyDialogues.push_back({
        "Evening. A soldier brings you cornbread and water. Whitmore returns\n"
        "and sits across from you, more relaxed now — almost friendly. This is\n"
        "the most dangerous kind of interrogation.",

        "Tell me about your route, Mr. Webb. Which towns did you pass through,\n"
        "and what goods were selling well in each?",

        {
            {"Danville, then Lynchburg — salt and flour are scarce everywhere.\n"
             "   I sold my last bolt of wool in Appomattox for twice the price.",
             true,
             "Whitmore nods, making a mental note. 'Salt is always scarce. The\n"
             "   blockade sees to that.' He seems partially satisfied — a real\n"
             "   merchant would know this.",
             -5},

            {"I... I came through Richmond. Yes, Richmond. Lots of soldiers there.",
             false,
             "Whitmore's eyes harden. 'Richmond is under martial law. No civilian\n"
             "   merchant moves through Richmond without papers. Where are yours?'\n"
             "   You have walked into a trap.",
             35},

            {"Mostly back-roads, Colonel. I prefer to avoid people during wartime.",
             false,
             "'A merchant who avoids people.' Whitmore leans forward. 'Merchants\n"
             "   live and die by people, Mr. Webb. Try again — and this time,\n"
             "   do not insult my intelligence.'",
             20},

            {"Frankfort and Versailles. Kentucky trade is still open if you know\n"
             "   the right ferryman. Tobacco and leather move well westward.",
             true,
             "Whitmore leans back. 'Kentucky. That border is a snake's nest.\n"
             "   You must be either very brave or very foolish.' He almost smiles.\n"
             "   Your knowledge of trade routes has calmed him somewhat.",
             -10}
        }
    });

    // ── Scene 4: A loyalist accuses you ───────────────────
    spyDialogues.push_back({
        "Morning. A new face appears — Sergeant Boone, a hard-eyed man with a\n"
        "scar across his jaw. He claims to recognize you from a different place\n"
        "entirely. He stares at you with certainty.",

        "I saw this man in Washington City three months ago. He was dining with\n"
        "a Union officer. I never forget a face. Colonel, this man is no merchant.",

        {
            {"Sergeant, I dine with anyone who will pay for my samples.\n"
             "   I sell to both sides — it is called staying in business.",
             true,
             "Whitmore looks at Boone. 'Is that so unusual, Sergeant? Merchants\n"
             "   are like water — they flow wherever profit leads.' Boone scowls\n"
             "   but cannot argue. Whitmore waves him off.",
             10},

            {"He is lying! I have never been to Washington in my life!",
             false,
             "Boone steps forward. 'Then explain this —' He pulls out a sketch.\n"
             "   It looks exactly like you. Your denial has made things far worse.",
             40},

            {"Washington is a large city, Sergeant. Half the country passes through it.",
             true,
             "Whitmore nods slowly. 'The Sergeant may be mistaken. Or you may\n"
             "   be very unlucky. Either way, I will decide.' He sends Boone out.",
             5},

            {"I want a lawyer. This is unlawful detention and I will not stand\n"
             "   for accusations from your subordinates.",
             false,
             "Whitmore stands. 'A lawyer. In a war zone. That is almost amusing.\n"
             "   Take him back to the barn. He stays until I am satisfied.'",
             25}
        }
    });

    // ── Scene 5: The escape window ────────────────────────
    spyDialogues.push_back({
        "Midday. You are left alone for a brief moment while guards change shifts.\n"
        "Whitmore steps outside to inspect the perimeter. There is a small window\n"
        "at the back of the barn — just large enough. You hear voices approaching.\n"
        "You have perhaps ninety seconds.",

        "(Whitmore returns, holding a telegraph sheet. His expression is unreadable.)\n"
        "'Mr. Webb. I have just received a reply from Cincinnati regarding your shop.\n"
        "Interesting results. Is there anything you wish to tell me — now, before\n"
        "I read this aloud?'",

        {
            {"Colonel, you are a man of obvious intelligence. I respect that.\n"
             "   I will simply say that whatever that paper says, I am not your\n"
             "   enemy — and I may yet prove useful to you.',",
             true,
             "Whitmore holds your gaze for a long, still moment. Then — almost\n"
             "   imperceptibly — he nods. He drops the telegraph into a candle\n"
             "   flame. 'I find my memory for names has been poor today.' He\n"
             "   unlocks the barn door. 'The road north is clear until dawn.'",
             -30},

            {"I demand to see that telegraph! You have no right—",
             false,
             "Whitmore cuts you off. 'The telegraph confirms no Elias Webb\n"
             "   operates a shop in Cincinnati. Not now, not ever. Guards!'\n"
             "   Your cover story is destroyed.",
             50},

            {"I have nothing to confess. Read whatever you like, Colonel.",
             false,
             "Whitmore reads slowly. 'There is no record of a merchant named\n"
             "   Elias Webb in Cincinnati's trade register.' He folds it.\n"
             "   'That will be all, Mr. Webb. Or whoever you are.'",
             45},

            {"I was hired by a private party to observe Confederate movements.\n"
             "   Not Union Army — private. I am a journalist, not a soldier.",
             false,
             "Whitmore shakes his head. 'A journalist. A spy. A merchant. You\n"
             "   have been three different men today. I am done guessing.' He\n"
             "   signals for the guard. 'Lock him up properly this time.'",
             35}
        }
    });

    // ── Scene 6: The final moment ─────────────────────────
    spyDialogues.push_back({
        "The road is dark and empty. You move through the tree line, heart\n"
        "hammering. Behind you, Whitmore stands at the barn door, watching.\n"
        "A sentry appears ahead — blocking the only path to the river crossing.",

        "(The sentry raises his musket.)\n"
        "'Halt! Identify yourself or I fire!'",

        {
            {"'Colonel Whitmore sent me on an errand. Check with him if you like —\n"
             "   I will wait right here.' (You stand calmly, betting he won't leave his post.)",
             true,
             "The sentry hesitates — soldiers never abandon posts to verify orders.\n"
             "   He lowers his musket slightly. 'Be quick about it then.' You walk\n"
             "   past, measured steps, until the darkness swallows you. You are free.",
             0},

            {"(You bolt and run — straight into the dark.)",
             false,
             "The shot rings out immediately. You feel a searing pain in your leg\n"
             "   and go down hard. Lanterns converge from every direction. Captured.",
             60},

            {"'I am a civilian prisoner, released by the Colonel. Let me pass.'",
             false,
             "The sentry shakes his head. 'No civilian walks out at midnight.\n"
             "   Nobody told me about any release.' He fires a warning shot and\n"
             "   shouts for backup. The camp erupts.",
             50},

            {"(You attempt to disarm him silently.)",
             false,
             "He is faster than he looks. A sharp crack — the butt of the musket\n"
             "   connects with your temple. You crumple. When you wake, it is dawn\n"
             "   and you are in irons. The game is over.",
             60}
        }
    });
}

// ══════════════════════════════════════════════════════════
//  REBEL LEADER PATH — 6 Scenes
//  Player = Colonel James Whitmore (Union double agent)
//  NPC    = Viktor Schell, arms dealer; rebels; Union handler
// ══════════════════════════════════════════════════════════
void DialogueManager::buildRebelDialogues() {

    // ── Scene 1: Meeting the arms dealer ──────────────────
    rebelDialogues.push_back({
        "Richmond, Virginia, 1863. In a private room above a tavern, you sit\n"
        "across from Viktor Schell — a German-born arms merchant who supplies\n"
        "weapons to whoever can pay. Two rebel soldiers flank the door.\n"
        "They answer to you. But Schell's eyes are measuring, calculating.",

        "Colonel Whitmore. I have heard your name. You want three hundred\n"
        "Enfield rifles and powder for six months. That is a serious order.\n"
        "Why should I trust a man I have only just met?",

        {
            {"Because I have gold — and gold does not require trust.\n"
             "   I can pay half now, half on delivery. In coin.",
             true,
             "Schell's eyes light briefly before he controls the expression.\n"
             "   'Coin. That changes the conversation considerably, Colonel.\n"
             "   Let us talk terms.' The deal is moving forward.",
             10},

            {"Because the Confederate Army stands behind this purchase.\n"
             "   You will have protection and future contracts.",
             false,
             "Schell shakes his head slowly. 'Confederate protection is worth\n"
             "   less every month, Colonel. The Union blockade tightens. I need\n"
             "   more than promises from a losing side.'",
             25},

            {"You do not need to trust me, Schell. You need my payment.",
             true,
             "Schell laughs — a short, genuine sound. 'A pragmatist. Good.\n"
             "   I do business with pragmatists.' He pours two glasses of brandy.\n"
             "   'Then let us discuss delivery logistics, Colonel.'",
             5},

            {"I have connections in Europe who could expand your markets\n"
             "   significantly. This deal is a door to something much larger.",
             false,
             "Schell leans forward. 'European connections. Every desperate buyer\n"
             "   claims connections. Show me the gold first — then we talk of doors.'",
             20}
        }
    });

    // ── Scene 2: Schell tests your loyalties ──────────────
    rebelDialogues.push_back({
        "Schell orders food and the conversation grows more comfortable.\n"
        "Then, without warning, he drops a name casually — like a coin on\n"
        "a table — watching your face for any reaction.",

        "I heard a curious thing, Colonel. A Union intelligence officer named\n"
        "Carver has been asking questions about Confederate officers who\n"
        "purchase weapons through back channels. His list — they say — includes\n"
        "your name. What do you make of that?",

        {
            {"Carver is thorough — I will give the Yankees that. But a name\n"
             "   on a list means nothing. Half of Richmond is on their lists.\n"
             "   It keeps their clerks employed.",
             true,
             "Schell relaxes visibly. A man who is afraid would protest too much\n"
             "   or deflect awkwardly. Your boredom with the subject reads as genuine\n"
             "   confidence. 'Fair enough, Colonel.' He moves on.",
             -5},

            {"(You tense visibly) — Who told you about Carver? Where did you\n"
             "   hear that name?",
             false,
             "Schell's eyes sharpen instantly. Your reaction told him everything.\n"
             "   'An interesting response, Colonel. Most men would simply deny it.\n"
             "   You asked about the source. Why does the source matter to you?'",
             40},

            {"I do not know any Carver. And I do not appreciate being\n"
             "   investigated, Schell. We should focus on the business at hand.",
             false,
             "Schell tilts his head. 'Touchy. That is almost as interesting as\n"
             "   knowing the name Carver would have been.' He makes a small note.",
             20},

            {"Carver is a problem for other men. I sleep well, Schell.\n"
             "   Should I be worried about something you know?",
             true,
             "Schell waves a hand. 'No, no — I test everyone I deal with.\n"
             "   It is professional habit.' He seems satisfied. You have passed\n"
             "   the first real test without flinching.",
             -10}
        }
    });

    // ── Scene 3: Logistics and the Union's hidden hand ─────
    rebelDialogues.push_back({
        "The deal is moving forward. Schell lays a map on the table.\n"
        "Delivery routes, crossing points, and drop locations are discussed.\n"
        "You know — because your Union handler told you — that a specific\n"
        "crossing point will be intercepted. You must steer Schell toward it\n"
        "without him knowing why.",

        "I propose delivering through the Shenandoah Valley crossing at\n"
        "Harper's Ferry — it is familiar ground for my drivers. Or we could\n"
        "use the mountain pass near Staunton. Your call, Colonel.",

        {
            {"Harper's Ferry makes sense. I know the checkpoints there\n"
             "   and my men can provide an escort through the Valley.",
             true,
             "Schell nods, satisfied. You have guided him exactly where the Union\n"
             "   wants the shipment. 'Harper's Ferry it is. My drivers will be\n"
             "   ready in ten days.' The trap is quietly set.",
             0},

            {"The Staunton pass — it is more discreet and the roads are\n"
             "   better in autumn.",
             false,
             "You have just routed the shipment away from the Union ambush.\n"
             "   Your handler will be furious. The deal advances, but the\n"
             "   weapons may reach the Confederacy intact.",
             30},

            {"It does not matter to me — choose whichever your drivers prefer.",
             false,
             "Schell looks up. 'A Colonel unconcerned about where three hundred\n"
             "   rifles travel. That strikes me as... careless, for a military man.'",
             25},

            {"I need to consult with my quartermaster before deciding.\n"
             "   Can we revisit this tomorrow?",
             false,
             "Schell's patience visibly thins. 'Every delay increases my risk,\n"
             "   Colonel. Men who cannot decide quickly rarely survive long\n"
             "   in either business or war.' He drums his fingers.",
             15}
        }
    });

    // ── Scene 4: A rebel soldier grows suspicious ──────────
    rebelDialogues.push_back({
        "One of your own soldiers — Lieutenant Crabb, a fiercely loyal man —\n"
        "pulls you aside before the meeting resumes. He has been watching\n"
        "Schell's interpreter and noticed something. He speaks quietly but\n"
        "his eyes are troubled.",

        "Colonel, with respect — the interpreter whispered something to Schell\n"
        "that I could not hear. After that, Schell looked at you differently.\n"
        "And you chose Harper's Ferry mighty fast without your usual calculations.\n"
        "Sir... are you certain about this man Schell?",

        {
            {"Crabb, I have run operations longer than you have worn that uniform.\n"
             "   Harper's Ferry is tactically sound and I made the call. Return\n"
             "   to your post and trust your commanding officer.",
             true,
             "Crabb stiffens — the soldier's instinct to obey overrides his doubt.\n"
             "   'Yes sir.' He returns to the door. You have quieted him without\n"
             "   raising further alarm. But his suspicion remains, dormant.",
             5},

            {"(You confide in Crabb — tell him you are a Union agent.)",
             false,
             "Crabb's face goes pale, then hard. 'Traitor.' He draws his pistol.\n"
             "   The seconds that follow end your mission permanently.",
             80},

            {"You raise a fair point, Lieutenant. Let us postpone the deal\n"
             "   and reassess Schell's credentials.",
             false,
             "Schell, hearing the delay, grows cold. 'If you are having doubts,\n"
             "   Colonel, perhaps we are not suited to do business.' The deal\n"
             "   begins to collapse — and with it, the Union's plan.",
             35},

            {"The interpreter? He is Schell's man — they always whisper.\n"
             "   It means nothing. Schell is motivated by gold, not loyalty.\n"
             "   That makes him predictable and safe.",
             true,
             "Crabb considers this. 'If you say so, Colonel.' He seems partially\n"
             "   reassured by your confident reasoning. You return to the table.",
             0}
        }
    });

    // ── Scene 5: Schell demands proof of Confederate backing ─
    rebelDialogues.push_back({
        "The brandy has made Schell bolder. He places both hands on the table\n"
        "and looks at you with a merchant's directness. Around the room,\n"
        "his own guards have subtly repositioned. Something has shifted.",

        "Colonel, I have one final condition before we sign. I need a letter —\n"
        "written and sealed — from a senior Confederate commander authorizing\n"
        "this purchase. Without that, my partners will not release the shipment.\n"
        "Surely that is not a problem for a man of your rank?",

        {
            {"General Beauregard's office authorized this purchase verbally.\n"
             "   A written letter takes two weeks through proper channels.\n"
             "   If you cannot move on that timeline, I find another supplier.",
             true,
             "Schell blinks — he had not expected you to call his bluff. The\n"
             "   power has shifted. 'Two weeks is acceptable. I will wait for\n"
             "   the letter.' The deal holds, and you have bought time for\n"
             "   your Union handler to complete the interception plan.",
             -5},

            {"I will have the letter to you by morning.",
             false,
             "Schell raises an eyebrow. 'By morning. From General Beauregard.\n"
             "   That would require a telegraph tonight and a courier by dawn.\n"
             "   You are either very powerful — or very desperate.' He watches you.",
             30},

            {"That kind of paperwork creates a record I would prefer\n"
             "   did not exist. Surely we can proceed on mutual trust.",
             false,
             "Schell stands slowly. 'Mutual trust. In wartime. From a man who\n"
             "   just asked me to route three hundred rifles through enemy-adjacent\n"
             "   territory.' He gestures to his guards. 'I think we are done here.'",
             45},

            {"Schell, let us be plain with each other. You do not need\n"
             "   a letter. You need assurance the gold is real. I have it here.",
             true,
             "You place a leather pouch on the table. The sound of gold coin\n"
             "   is universal. Schell's caution dissolves almost immediately.\n"
             "   'That is... a compelling argument, Colonel.' The deal is sealed.",
             -10}
        }
    });

    // ── Scene 6: The final handoff ─────────────────────────
    rebelDialogues.push_back({
        "Ten days later. Harper's Ferry. The wagons roll through the pre-dawn\n"
        "mist toward the crossing. You stand with Schell, watching. Somewhere\n"
        "in the tree line, you know Union soldiers are waiting. All you need\n"
        "to do is walk away before the shooting starts.",

        "(A rider arrives with an urgent message. Schell reads it and\n"
        "turns to you, something cold in his eyes.)\n"
        "'Colonel. My contact in Richmond says a Union telegraph was sent\n"
        "from this region two nights ago. Someone warned them about this\n"
        "crossing. Do you know anything about that?'",

        {
            {"(You look at the wagons, then at Schell, and lower your voice.)\n"
             "   'Schell — walk away from those wagons. Right now. Do not ask why.'",
             true,
             "Schell stares at you — and something clicks. His eyes widen with\n"
             "   understanding. He is a survivor before he is a merchant. He turns\n"
             "   and walks briskly in the opposite direction. Moments later, Union\n"
             "   soldiers emerge from the tree line. The wagons are captured. You\n"
             "   disappear into the morning fog. Mission complete.",
             0},

            {"'An absurd accusation. Perhaps your contact is the one\n"
             "   feeding information to the Union, Schell.'",
             false,
             "Schell's guards move forward. 'A fine deflection. But the telegraph\n"
             "   was traced to a hotel where only one party was staying — yours,\n"
             "   Colonel. I should have trusted my instincts.' He nods to his men.",
             60},

            {"'I know nothing about any telegraph. Search my men\n"
             "   if you feel the need.'",
             false,
             "Schell searches — and finds the cipher key your Union handler\n"
             "   gave you, overlooked in your coat lining. His expression\n"
             "   turns to stone. 'So. A double-dealer after all.' It ends here.",
             65},

            {"(You say nothing, turn, and walk calmly toward your horse.)",
             false,
             "Schell shouts. His guards draw. The sound of gunfire breaks the\n"
             "   morning silence. You never reach the horse. The mission dies\n"
             "   with you in the mud at Harper's Ferry.",
             70}
        }
    });
}

// ══════════════════════════════════════════════════════════
//  Display + Input Helpers
// ══════════════════════════════════════════════════════════
void DialogueManager::printDivider() const {
    std::cout << "\n" << std::string(62, '=') << "\n";
}

void DialogueManager::printSituation(const DialogueNode& node) const {
    printDivider();
    std::cout << "\n" << node.situation << "\n\n";
    std::cout << std::string(62, '-') << "\n";
    std::cout << node.npcLine << "\n";
    std::cout << std::string(62, '-') << "\n\n";
}

int DialogueManager::promptPlayerChoice(const DialogueNode& node) const {
    for (int i = 0; i < static_cast<int>(node.choices.size()); ++i) {
        std::cout << "  [" << (i + 1) << "] " << node.choices[i].text << "\n\n";
    }
    std::cout << "Your choice (1-4): ";

    int choice = 0;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > 4) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "  Please enter 1, 2, 3, or 4: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice - 1;   // Convert to 0-based index
        }
    }
}

// ─── Main Public Method: Run One Dialogue Node ────────────
DialogueResult DialogueManager::runNode(int nodeIndex, bool isSpyPath) const {
    const auto& tree = isSpyPath ? spyDialogues : rebelDialogues;
    const DialogueNode& node = tree[nodeIndex];

    printSituation(node);
    int choiceIdx = promptPlayerChoice(node);
    const Choice& chosen = node.choices[choiceIdx];

    std::cout << "\n" << std::string(62, '-') << "\n";
    std::cout << chosen.consequence << "\n";
    std::cout << std::string(62, '-') << "\n\n";

    DialogueResult result;
    result.suspicionChange = chosen.suspicionDelta;
    result.message         = chosen.consequence;

    if (!chosen.isCorrect && chosen.suspicionDelta >= 45) {
        result.gameover    = true;
        result.playerWins  = false;
    } else if (chosen.isCorrect && nodeIndex == static_cast<int>(tree.size()) - 1) {
        result.gameover    = true;
        result.playerWins  = true;
    } else {
        result.gameover    = false;
        result.playerWins  = false;
    }

    return result;
}

int DialogueManager::getNodeCount(bool isSpyPath) const {
    return static_cast<int>(isSpyPath ? spyDialogues.size() : rebelDialogues.size());
}
