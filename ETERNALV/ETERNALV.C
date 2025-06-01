#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
#include <time.h>
#include <stdlib.h>
#include <dos.h>

typedef struct
{
	int hp;
	int maxHp;
	int atk;
	int constAtk;
	int def;
	int constDef;
	int exp;
	int lvl;
} Character;

Character player = {50, 50, 10, 10, 5, 5, 0, 1};

// monsters
typedef struct normalEty
{
	char name[20];
	int enemyHp;
	const int constHp;
	char atkName[20];
	int dmg;
	char dropName[20];
	int dropQty;
	int qty;
	int exp;
} normalEty;

int etyTF[3] = {0, 0};
int etyPick, randomNum, mobAry, bossAry;

normal Ety;

normalEty mob[8] = {
	{"Slime", 25, 25, "Clash", 5, "susWater", 5, 0, 40},
	{"Goblin", 50, 50, "Punch", 7, "herbs", 2, 0, 50},
	{"Bandit", 75, 75, "Slash", 10, "bottle", 4, 0, 60},
	{"Gnome", 80, 80, "Ankle Bite", 12, "Gnome Hat", 1, 0, 70},
	{"Necromancer", 100, 100, "Death Charge", 20, "Poison Stone", 2, 0, 80},
	{"Griffin", 120, 120, "Talon Strike", 23, "Claw Powder", 2, 0, 90},
	{"Possesed Armor", 150, 150, "Stiff Pierce", 25, "Armor's Powder", 2, 0, 100},
	{"Orc", 200, 200, "Club Rage", 30, "Stick", 1, 0, 110}};

normalEty boss[5] = {
	{"Accidiam", 1500, 1500, "Terra Barrage", 150, "", 1, 0, 500},
	{"Desparatio", 1300, 1300, "Desolate Tide", 100, "", 1, 0, 600},
	{"Furorem", 1300, 1300, "Scorching Solitude", 200, "", 1, 0, 700},
	{"Solitudo", 1500, 1500, "Vacuum Pulse", 130, "", 1, 0, 800},
	{"Great Exolvuntur", 3000, 3000, "Binding Chain", 150, "", 1, 0, 900}};

typedef struct item
{
	char craftName[20];
	float effect;
	int qty;
	int turn;
	const int constTurn;
} item;

item items[4] = {
	{"Healing Potion", 50, 0, 1, 0},
	{"Poison Potion", 5, 0, 1, 5},
	{"Power Potion", .5, 0, 1, 3},
	{"Defence Potion", .5, 0, 1, 3}};

int TF[2] = {0, 0};
int effectTF[3] = {0, 0, 0};

// Story  Progression
void chapter1P1();
void interaction();
void chapter1P2();
void finale();
void End();
void credits();
// Selections
void mainMenu();
void travel();
void hunt();
void inventory();
void meditate();
void displayStats();
// Player status
void levelUp();
void equipItem(Character *player, int bonusAtk, int bonusDef);
void takeDamage(Character *player, int damage);
// Death/Reincarnation Sequence
void abandonQuest();
void reincarnate(Character *player);
void restForEternity();
void deathScreen(Character *player);
void finalScore();
// In game mechanics
void etyPicker();
void combatSyst();
void bosscombatSyst();
void crafting();
void combatSyst();
void equipSyst();
// Effects
void resetEffect();
void poisonEffect();
void powerEffect();
void defenceEffect();

int secretEnd = 1;
int currentChapter = 1;
int playerAlive = 1;

//                    --- STORY PROGRESSION ----

void chapter1P1()
{
	clrscr();
	printf("\n    __------------------------------__\n");
	printf("   |  Chapter 1: Wherefore art thou?  |\n");
	printf("  |        Phase 1: In the Forest      |\n");
	printf("   |__------------------------------__|\n");
	printf("\n\n");
	printf("'Ugh...");
	delay(1500);
	printf("What was that.' (enter)");
	getch();
	clrscr();
	printf("\n\n-- You blink, eyes squinting against the harsh light. \nEverythiing around you is too bright. (enter)");
	getch();
	clrscr();
	printf("\n\n-- Where are you? What is this place?");
	printf("\n\n'Wh..");
	delay(1000);
	printf(" where...");
	delay(1000);
	printf(" why' (enter)");
	getch();
	clrscr();
	printf("\n\n-- As  you  sit up, your back presses againnst a crumbling stone wall--");
	delay(2000);
	printf("\n\n'ruins,  perhaps?'");
	delay(1000);
	printf("\n\n-- In your hand, there's something...");
	delay(2500);
	printf("\n\n'An amulet?' (enter)");
	getch();
	clrscr();
	printf("\n\n-- Somehow it feels significant. \nSo you tuck it into your pocket to keep it safe. (enter)");
	getch();
	mainMenu();
}

void chapter1P2()
{
	int choice;
	clrscr();
	printf("\n   __------------------------------__\n");
	printf("   |   Chapter 1: Wherefore art thou? |\n");
	printf("  |        Phase 2: Encounter          |\n");
	printf("   |__------------------------------__|\n");
	printf("\n\n");
	printf("-- Hours pass. The silennce of the forest is unnerving,\nbroken only by the occasional rustling of leaves. (enter)");
	getch();
	clrscr();
	printf("\n\n-- You haven't seen a soul.");
	delay(3000);
	printf("\n\n-- No rivers or streams.");
	delay(2000);
	printf("\n\n-- Just trees, rocks, and endless wilderness. (enter)");
	getch();
	clrscr();
	printf("\n\n'What's going on anyways?' you mutter to yourself,\n feeling the weight of confusion pressing down on you. (enter)");
	getch();
	clrscr();
	printf("\n\n-- Then suddenly you hear it - a splashing sound. (enter)");
	getch();
	clrscr();
	printf("\n\n-- Not like water... ");
	delay(2500);
	printf("something squelchy, almost alive. (enter)");
	getch();
	clrscr();
	printf("\n\n-- You stop and listen. The sound grows louder, then...");
	delay(1000);
	printf(" it moves. (enter)");
	getch();
	clrscr();
	printf("\n\n-- You follow the noise, your steps slow, careful. (enter)");
	getch();
	clrscr();
	printf("\n\n-- And there it is. A body of water... ");
	delay(1500);
	printf("But not the calm, serene kind you expected.\n This one's alive. Towering over you. (enter)");
	getch();
	clrscr();
	printf("\n\n-- This slime is hostile. Deak with it quick!");
	getch();
	clrscr();
	printf("\nYou are hit by the slime");
	getch();
	clrscr();
	// combat
	mobAry = 0;
	etyTF[0]++;
	etyPicker();
	combatSyst();
	if (playerAlive)
	{
		clrscr();
		printf("\nLook at you, a natural!");
		printf("\n\n-- A voice from afar echoed, you looked around\n");
		printf(" and it was coming from a woman. (enter)");
		printf("\n-- You wiped off bits and pieces of slime on you");
		printf("\n Reminder: Your words greatly impact you life.");
		printf("\n---------- How would you interact? ----------\n");
		printf("\n 1. Ask where this place is.");
		printf("\n 2. Ask for a nearby settlement.");
		printf("\n 3. Ignore her");
		printf("\n\n What will you say/do?: ");
		scanf("%d", &choice);

		if (choice == 1)
		{
			clrscr();
			printf("\n 'May I ask where this place is?' (enter)");
			getch();
			clrscr();
			printf("\n 'A lost traveler? Well, we are at the foor of Mt. Vatoo' (enter)");
			getch();
			clrscr();
			printf("\n 'There's a city nearby. You're lucky I found you\n come with me. (enter)");
			getch();
			clrscr();
			printf("\n\n-- Seems like shes trustworthy,");
			delay(2300);
			printf(" and a the only ticket outta this forest. (enter)");
			getch();
		}
		else if (choice == 2)
		{
			clrscr();
			printf("\n 'Do you know a nearby...");
			delay(1500);
			printf(" Settlement?' (enter)");
			getch();
			clrscr();
			printf("\n '...");
			delay(1000);
			printf(" Pfft.'");
			delay(1000);
			printf("\n\n 'Pwahahaha'");
			delay(1000);
			printf("\n\n 'Ahem, I'm sorry, Good Sir.(mocking)");
			printf("\n There is actually one. Follow me. And no need to be so stern");
			getch();
			clrscr();
			printf("\n\n-- Seems like shes trustworthy,");
			delay(2300);
			printf(" and a the only ticket outta this forest. (enter)");
			getch();
		}
		else if (choice == 3)
		{
			secretEnd += 1;
			clrscr();
			printf("\n '...' (enter)");
			getch();
			clrscr();
			printf("\n ' Hey.");
			delay(1000);
			printf(" Buffoon");
			delay(1000);
			printf(" , you won't last a night out here.\n You're obviously not from 'round here.");
			printf("\n A city's nearby, so I suggest you follow me. Unless you wanna meet\n the parents of the poor slime you killed.' (enter)");
			getch();
			printf("\n\n-- Seems like shes trustworthy,");
			delay(2300);
			printf(" and a the only ticket outta this forest. (enter)");
			getch();
		}
		else
		{
			printf("\n Invalid choice. Again.");
			getch();
			return;
		}
		mainMenu();
	}
}

void finale()
{
	clrscr();
	printf("\n  ___------------------------------___\n");
	printf("   <_      Finale: The Sentinels      _>\n");
	printf("    _>                               <_\n");
	printf("   <__------------------------------___>\n\n");
	printf("-- The sentinel of Earth, the embodiment of Apathy.\n Accidiam emerges.");
	getch();
	bossAry = 0;
	etyTF[1]++;
	bosscombatSyst();
	printf("-- Sentinel Fell");
	secretEnd += 1;
	getch();
	clrscr();
	printf("-- The sentinel of Water, the embodiment of Desperation.\n Desparatio emerges.");
	getch();
	bossAry = 1;
	etyTF[1]++;
	bosscombatSyst();
	printf("-- Sentinel Fell");
	secretEnd += 1;
	getch();
	clrscr();
	printf("-- The sentinel of Fire, the embodiment of Fury.\n Furorem emerges.");
	getch();
	bossAry = 2;
	etyTF[1]++;
	bosscombatSyst();
	printf("-- Sentinel Fell");
	secretEnd += 1;
	getch();
	clrscr();
	printf("-- The sentinel of Air, the embodiment of Loneliness.\n Solitudo emerges.");
	getch();
	bossAry = 3;
	etyTF[1]++;
	bosscombatSyst();
	printf("-- Sentinel Fell");
	secretEnd += 1;
	getch();
	clrscr();
	printf("-- The curse of Exolvuntur\n");
	printf("  fell upon you.\n ");
	getch();
	printf("-- Darkness started to creep your vision...");
	getch();
	if (secretEnd >= 6)
	{
		End();
		return;
	}
	else
	{
		currentChapter = 1;
	}
}

void End()
{
	clrscr();
	printf("\n  ___------------------------------___\n");
	printf("   <_          Secret Ending:         _>\n");
	printf("    _>       The Great Exolvuntur    <_\n");
	printf("   <__------------------------------___>\n");
	printf("\n\n-- Dust started swirling around the fallen,\n shaping up an Ethereal being.");
	getch();
	printf("-- An enormous and crushing aura filled the room.\n\n");
	printf("-- The Deity of Cycle, Embodiment of time.\n\n Exolvuntur emerges.");
	getch();
	bossAry = 4;
	etyTF[1]++;
	bosscombatSyst();
	printf("-- It is finally over.\n\n");
	getch();
	printf("-- The Great Exolvuntur; manipulator of fate,\n dictator of destiny, has fallen.");
	getch();
	clrscr();
	printf("-- Without Exolvuntur, what will become of the universe now?");
	getch();
	credits();
}

void credits()
{
	clrscr();
	printf("                 The Demo version Ends here");
	printf("\n            Thank you for trying Eternal Voyage");
	printf("\n\n  Life essence: %d", player.lvl * 100);
	printf("\n  (Life essence represents your in-game score)");
	getch();
	exit(0);
}

void mainMenu()
{
	int choice = 0;
	char key;

	while (1)
	{
		clrscr();
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n          What do you want to do?        ");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("%s Move onwards\n", choice == 0 ? "->" : "  ");
		printf("%s Hunt\n", choice == 1 ? "->" : "  ");
		printf("%s Inventory\n", choice == 2 ? "->" : "  ");
		printf("%s Meditate\n", choice == 3 ? "->" : "  ");
		printf("%s Abandon Journey\n", choice == 4 ? "->" : "  ");

		key = getch();

		if (key == 0 || key == -32)
		{
			key = getch();
			if (key == 72)
			{
				choice = (choice + 4) % 5;
			}
			else if (key == 80)
			{
				choice = (choice + 1) % 5;
			}
		}
		else if (key == 13)
		{
			switch (choice)
			{
			case 0:
				travel();
				currentChapter++;
				return;
			case 1:
				hunt();
				break;
			case 2:
				inventory();
				break;
			case 3:
				meditate(&player);
				break;
			case 4:
				abandonQuest();
				return;
			}
		}
	}
}

// Selections
void travel()
{
	printf("\nWalking...");
	getch();
}

void hunt()
{
	printf("\nYou have begun a hunt. Earn as many essence as you can.");
	combatSyst();
	getch();
}

void inventory()
{
	int i, j, empty = 0, choice = 0;
	char key;
	while (1)
	{
		for (i = 0; i < sizeof(mob) / sizeof(mob[0]); i++)
		{
			clrscr();
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			printf("\n                Inventory                ");
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			if (mob[i].qty > 0)
			{
				printf("%s Craft\n", choice == 0 ? "->" : "  ");
				printf("%s Back\n", choice == 1 ? "->" : "  ");
				for (j = 0; j < sizeof(mob) / sizeof(mob[0]); j++)
				{
					if (mob[j].qty > 0)
					{
						printf("\n%d \t: \t%s", mob[j].qty, mob[j].dropName);
					}
				}
				j = 0;
				for (j = 0; j < sizeof(items) / sizeof(items[0]); j++)
				{
					if (items[j].qty > 0)
					{
						printf("\n%d \t: \t%s", items[j].qty, items[j].craftName);
					}
				}
				j = 0;
				key = getch();

				if (key == 0 || key == -32)
				{
					key = getch();
					if (key == 72)
					{
						choice = (choice + 1) % 2;
					}
					else if (key == 80)
					{
						choice = (choice + 1) % 2;
					}
				}
				else if (key == 13)
				{
					switch (choice)
					{
					case 0:
						crafting();
						break;
					case 1:
						return;
					}
				}
			}
			else
			{
				empty += 1;
				if (empty == sizeof(mob) / sizeof(mob[0]))
				{
					printf("\nYour bag is Empty\n\n");
					getch();
					return;
				}
			}
		}
		empty = 0;
	}
}

void crafting()
{
	int choice = 0;
	char key;

	while (1)
	{
		clrscr();
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n                  Craft                  ");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("%s back\n\n", choice == 0 ? "->" : "  ");
		printf("%s %s\n", choice == 1 ? "->" : "  ", items[0].craftName);
		printf("%s %s\n", choice == 2 ? "->" : "  ", items[1].craftName);
		printf("%s %s\n", choice == 3 ? "->" : "  ", items[2].craftName);
		printf("%s %s\n\n", choice == 4 ? "->" : "  ", items[3].craftName);

		key = getch();

		if (key == 0 || key == -32)
		{
			key = getch();
			if (key == 72)
			{
				choice = (choice + 4) % 5;
			}
			else if (key == 80)
			{
				choice = (choice + 1) % 5;
			}
		}
		else if (key == 13)
		{
			switch (choice)
			{
			case 0:
				return;
			case 1:
				if (mob[0].qty > 0 && mob[1].qty > 0 && mob[2].qty > 0)
				{
					printf("Crafted %s", items[0].craftName);
					getch();
					mob[0].qty--;
					mob[1].qty--;
					mob[2].qty--;
					items[0].qty++;
				}
				else
				{
					printf("Insufficient amount of Item");
					getch();
				}
				break;
			case 2:
				if (mob[0].qty > 0 && mob[2].qty > 0 && mob[4].qty > 0)
				{
					printf("Crafted %s", items[1].craftName);
					getch();
					mob[0].qty--;
					mob[2].qty--;
					mob[4].qty--;
					items[1].qty++;
				}
				else
				{
					printf("Insufficient amount of Item");
					getch();
				}
				break;
			case 3:
				if (mob[0].qty > 0 && mob[2].qty > 0 && mob[5].qty > 0)
				{
					printf("Crafted %s", items[2].craftName);
					getch();
					mob[0].qty--;
					mob[2].qty--;
					mob[5].qty--;
					items[2].qty++;
				}
				else
				{
					printf("Insufficient amount of Item");
					getch();
				}
				break;
			case 4:
				if (mob[0].qty > 0 && mob[2].qty > 0 && mob[6].qty > 0)
				{
					printf("Crafted %s", items[3].craftName);
					getch();
					mob[0].qty--;
					mob[2].qty--;
					mob[6].qty--;
					items[3].qty++;
				}
				else
				{
					printf("Insufficient amount of Item");
					getch();
				}
				break;
			}
		}
	}
}

void equipSyst()
{
	int choice = 0;
	char key;

	while (1)
	{
		clrscr();
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n                Use Items                ");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("%s back\n\n", choice == 0 ? "->" : "  ");
		printf("%s %d\t:\t%s\n", choice == 1 ? "->" : "  ", items[0].qty, items[0].craftName);
		printf("%s %d\t:\t%s\n", choice == 2 ? "->" : "  ", items[1].qty, items[1].craftName);
		printf("%s %d\t:\t%s\n", choice == 3 ? "->" : "  ", items[2].qty, items[2].craftName);
		printf("%s %d\t:\t%s\n", choice == 4 ? "->" : "  ", items[3].qty, items[3].craftName);

		key = getch();

		if (key == 0 || key == -32)
		{
			key = getch();
			if (key == 72)
			{
				choice = (choice + 4) % 5;
			}
			else if (key == 80)
			{
				choice = (choice + 1) % 5;
			}
		}
		else if (key == 13)
		{
			switch (choice)
			{
			case 0:
				return;
			case 1:
				if (items[0].qty > 0)
				{
					if (player.hp < player.maxHp)
					{
						printf("%s used", items[0].craftName);
						player.hp += items[0].effect;
						items[0].qty--;
						if (player.hp > player.maxHp)
						{
							player.hp = player.maxHp;
						}
					}
					else
					{
						printf("Already reached max HP");
					}
				}
				else
				{
					printf("Insufficent amount of item");
				}
				getch();
				break;
			case 2:
				if (items[1].qty > 0)
				{
					effectTF[0] += 2;
					printf("%s used", items[1].craftName);
					items[1].turn = items[1].constTurn;
					items[1].qty--;
					if (items[1].turn > 1)
					{
						items[1].turn += items[1].constTurn;
					}
				}
				else
				{
					printf("Insufficent amount of item");
				}
				getch();
				break;
			case 3:
				if (items[2].qty > 0)
				{
					if (effectTF[1] > 1)
					{
						printf("This item cannot be stacked");
					}
					else
					{
						effectTF[1] += 2;
						printf("%s used", items[2].craftName);
						items[2].turn = items[2].constTurn;
						items[2].qty--;
					}
				}
				else
				{
					printf("Insufficent amount of item");
				}
				getch();
				break;
			case 4:
				if (items[3].qty > 0)
				{
					if (effectTF[2] > 1)
					{
						printf("This item cannot be stacked");
					}
					else
					{
						effectTF[2] += 2;
						printf("%s used", items[3].craftName);
						items[3].turn = items[3].constTurn;
						items[3].qty--;
					}
				}
				else
				{
					printf("Insufficent amount of item");
				}
				getch();
				break;
			}
		}
	}
}

// Effects

void resetEffect()
{
	int i;
	for (i = 0; i < sizeof(effectTF) / sizeof(effectTF[0]); i++)
	{
		items[i + 1].turn = 1;
		effectTF[i] = 0;
	}
	player.atk = player.constAtk;
	player.def = player.constDef;
}

void poisonEffect()
{

	if (effectTF[0] > 1)
	{
		if (etyTF[1] > 0)
		{
			printf("\n\n%s take %d due to the %s", boss[bossAry].name, items[1].effect, items[1].craftName);
			boss[bossAry].enemyHp -= items[1].effect;
		}
		else
		{
			printf("\n\n%s take %d due to the %s", mob[etyPick].name, items[1].effect, items[1].craftName);
			mob[etyPick].enemyHp -= items[1].effect;
		}
		items[1].turn--;
		getch();
	}
	else if (items[1].turn == 0)
	{
		effectTF[0]--;
		items[1].turn++;
	}
}

void powerEffect()
{

	if (effectTF[1] > 1)
	{
		if (TF[0] == 0)
		{
			player.atk += (player.atk * items[2].effect);
			TF[0]++;
		}
		items[2].turn--;
	}
	else if (items[2].turn == 0)
	{
		effectTF[1]--;
		TF[0]--;
		items[2].turn++;
		player.atk = player.constAtk;
	}
}

void defenceEffect()
{

	if (effectTF[2] > 1)
	{
		if (TF[1] == 0)
		{
			player.def += (player.def * items[3].effect);
			TF[1]++;
		}
		items[3].turn--;
	}
	else if (items[3].turn == 0)
	{
		effectTF[2]--;
		TF[1]--;
		items[3].turn++;
		player.def = player.constDef;
	}
}

// Combats

void etyPicker()
{
	if (etyTF[0] > 0)
	{
		etyPick = mobAry;
	}
	else
	{
		srand(time(0));
		randomNum = rand() % sizeof(mob) / sizeof(mob[0]);
		etyPick = randomNum;
	}
}

void combatSyst()
{
	int i, j, damageTaken, choice = 0, turn = 0, def = 0, stan = 0, round = 1;
	char key;

	etyPicker();

	while (1)
	{
		for (i = 0; mob[etyPick].enemyHp > 0 && player.hp > 0; i++)
		{
			if (turn == 0 || stan > 0)
			{
				clrscr();
				printf("You\t\t\tEnemy Name : %s", mob[etyPick].name);
				printf("\nHP : %d\t\t\tHP : %d", player.hp, mob[etyPick].enemyHp);
				printf("\n\nRound : %d", round);
				printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				printf("\n          What do you want to do?        ");
				printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("%s Attack 1\n", choice == 0 ? "->" : "  ");
				printf("%s Attack 2\n", choice == 1 ? "->" : "  ");
				printf("%s Defence\n\n", choice == 2 ? "->" : "  ");
				printf("%s Use Items\n\n", choice == 3 ? "->" : "  ");

				key = getch();

				if (key == 0 || key == -32)
				{
					key = getch();
					if (key == 72)
					{
						choice = (choice + 3) % 4;
					}
					else if (key == 80)
					{
						choice = (choice + 1) % 4;
					}
				}
				else if (key == 13)
				{
					switch (choice)
					{
					case 0:
						powerEffect();
						printf("You dealt : %d damage", player.atk);
						mob[etyPick].enemyHp -= player.atk;
						getch();
						if (stan > 0)
						{
							stan--;
							round++;
							poisonEffect();
						}
						else
						{
							turn++;
						}
						break;
					case 1:
						powerEffect();
						printf("You dealt : %d damage", player.atk * 2);
						mob[etyPick].enemyHp -= player.atk * 2;
						getch();
						if (stan > 0)
						{
							stan--;
							round++;
							poisonEffect();
						}
						else
						{
							turn++;
						}
						break;
					case 2:
						if (stan == 0)
						{
							printf("Got into a defensive stance!");
							def++;
							getch();
							turn++;
						}
						else if (stan == 1)
						{
							printf("\n\nYou charge your defencive stance");
							getch();
						}
						else
						{
							printf("You're already in a defensive stance");
							getch();
						}
						break;
					case 3:
						equipSyst();
						break;
					}
				}
			}
			else
			{
				clrscr();
				printf("You\t\t\tEnemy Name : %s", mob[etyPick].name);
				printf("\nHP : %d\t\t\tHP : %d", player.hp, mob[etyPick].enemyHp);
				printf("\n\nRound : %d", round);
				if (def == 0)
				{
					printf("\n\n%s used %s! You take %d damage", mob[etyPick].name, mob[etyPick].atkName, mob[etyPick].dmg);
					damageTaken = mob[etyPick].dmg - player.def;
					player.hp -= damageTaken;
					getch();
					turn--;
					round++;
				}
				else
				{
					printf("\n\n%s use %s! But you're able to defend against %s's attack!", mob[randomNum].name, mob[randomNum].atkName, mob[randomNum].name);
					getch();
					printf("\n\n%s got stunned!", mob[etyPick].name);
					getch();
					def--;
					round++;
					stan += 2;
				}
				poisonEffect();
				defenceEffect();
				for (i = 0; i < sizeof(effectTF) / sizeof(effectTF[0]); i++)
				{
					if (effectTF[i] == 1)
					{
						printf("\n\n%s effect ended", items[i + 1].craftName);
						effectTF[i]--;
						getch();
					}
				}
			}
		}
		clrscr();
		if (player.hp > 0)
		{
			printf("\nEnemy Fell");
			printf("\nYou've earned %d exp", mob[etyPick].exp);
			player.exp += mob[etyPick].exp;
			mob[etyPick].qty += mob[etyPick].dropQty;
			levelUp(&player);

			getch();
		}
		else
		{
			deathScreen(&player);
			getch();
		}
		resetEffect();
		for (j = 0; j < sizeof(etyTF) / sizeof(etyTF[0]); j++)
		{
			etyTF[j] = 0;
		}
		mob[etyPick].enemyHp = mob[etyPick].constHp;
		break;
	}
}

void bosscombatSyst()
{
	int i, j, damageTaken, choice = 0, turn = 0, def = 0, stan = 0, round = 1;
	char key;

	etyTF[1]++;

	while (1)
	{
		for (i = 0; boss[bossAry].enemyHp > 0 && player.hp > 0; i++)
		{
			if (turn == 0 || stan > 0)
			{
				clrscr();
				printf("You\t\t\tEnemy Name : %s", boss[bossAry].name);
				printf("\nHP : %d\t\t\tHP : %d", player.hp, boss[bossAry].enemyHp);
				printf("\n\nRound : %d", round);
				printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				printf("\n          What do you want to do?        ");
				printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("%s Attack 1\n", choice == 0 ? "->" : "  ");
				printf("%s Attack 2\n", choice == 1 ? "->" : "  ");
				printf("%s Defence\n\n", choice == 2 ? "->" : "  ");
				printf("%s Use Items\n\n", choice == 3 ? "->" : "  ");

				key = getch();

				if (key == 0 || key == -32)
				{
					key = getch();
					if (key == 72)
					{
						choice = (choice + 3) % 4;
					}
					else if (key == 80)
					{
						choice = (choice + 1) % 4;
					}
				}
				else if (key == 13)
				{
					switch (choice)
					{
					case 0:
						powerEffect();
						printf("You dealt : %d damage", player.atk);
						boss[bossAry].enemyHp -= player.atk;
						getch();
						if (stan > 0)
						{
							stan--;
							round++;
							poisonEffect();
						}
						else
						{
							turn++;
						}
						break;
					case 1:
						powerEffect();
						printf("You dealt : %d damage", player.atk * 2);
						boss[bossAry].enemyHp -= player.atk * 2;
						getch();
						if (stan > 0)
						{
							stan--;
							round++;
							poisonEffect();
						}
						else
						{
							turn++;
						}
						break;
					case 2:
						if (stan == 0)
						{
							printf("Got into a defensive stance!");
							def++;
							getch();
							turn++;
						}
						else if (stan == 1)
						{
							printf("\n\nYou charge your defencive stance");
							getch();
						}
						else
						{
							printf("You're already in a defensive stance");
							getch();
						}
						break;
					case 3:
						equipSyst();
						break;
					}
				}
			}
			else
			{
				clrscr();
				printf("You\t\t\tEnemy Name : %s", boss[bossAry].name);
				printf("\nHP : %d\t\t\tHP : %d", player.hp, boss[bossAry].enemyHp);
				printf("\n\nRound : %d", round);
				if (def == 0)
				{
					printf("\n\n%s used %s! You take %d damage", boss[bossAry].name, boss[bossAry].atkName, boss[bossAry].dmg);
					damageTaken = boss[bossAry].dmg - player.def;
					player.hp -= damageTaken;
					getch();
					turn--;
					round++;
				}
				else
				{
					printf("\n\n%s use %s! But you're able to defend against %s's attack!", boss[bossAry].name, boss[bossAry].atkName, boss[bossAry].name);
					getch();
					printf("\n\n%s got stunned!", boss[bossAry].name);
					getch();
					def--;
					round++;
					stan += 2;
				}
				poisonEffect();
				defenceEffect();
				for (i = 0; i < sizeof(effectTF) / sizeof(effectTF[0]); i++)
				{
					if (effectTF[i] == 1)
					{
						printf("\n\n%s effect ended", items[i + 1].craftName);
						effectTF[i]--;
						getch();
					}
				}
			}
		}
		clrscr();
		if (player.hp > 0)
		{
			printf("\nEnemy Fell");
			printf("\nYou've earned %d exp", boss[bossAry].exp);
			player.exp += boss[bossAry].exp;
			mob[etyPick].qty += boss[bossAry].dropQty;
			levelUp(&player);

			getch();
		}
		else
		{
			deathScreen(&player);
			getch();
		}
		resetEffect();
		for (j = 0; j < sizeof(etyTF) / sizeof(etyTF[0]); j++)
		{
			etyTF[j] = 0;
		}
		boss[bossAry].enemyHp = boss[bossAry].constHp;
		break;
	}
}

// Function to handle leveling up
void levelUp(Character *player)
{
	if (player->exp >= 100)
	{
		printf("\nYou Leveled up!");
		player->exp -= 100;	   // Deduct experience points after leveling up
		player->lvl++;		   // Increment level
		player->hp += 50;	   // Increase HP
		player->maxHp += 50;   // Increase Max Hp
		player->atk += 5;	   // Increase Attack
		player->constAtk += 5; // constant atk
		player->def += 3;	   // Increase Defense
		player->constDef += 3; // constant def
	}
	else
	{
		printf("\nNot enough EXP to level up!\n");
	}
}

void displayStats(const Character *player)
{
	printf("\n+---------------------------------------+\n");
	printf("|          Character Stats              |\n");
	printf("+---------------------------------------+\n");
	printf("| Level: %-7d  | Health: %-6d      |\n", player->lvl, player->hp);
	printf("| Attack: %-6d  | Defense: %-6d     |\n", player->atk, player->def);
	printf("| EXP: %-7d    |                     |\n", player->exp);
	printf("+---------------------------------------+\n");
}

void meditate(const Character *player)
{
	printf("\n --Your current status is--\n");
	displayStats(player);
	getch();
}

// End game sequence

void reincarnate(Character *player)
{
	printf("\n\n--You  have chosen to reincarnate.\n Your journey shall begin once again.");
	getch();
	player->hp = 50 + (player->lvl - 1) * 20;
	playerAlive = 1;
	currentChapter = 1;
}

void restForEternity()
{
	printf("\n You chose to rest. So be it.");
	getch();
	credits();
}

void deathScreen(Character *player)
{
	int choice = 0;
	char key;
	while (1)
	{
		clrscr();
		printf("\n");
		printf("\n         You have Fallen        ");
		printf("\n");
		printf("          %s Reincarnate\n", choice == 0 ? "->" : "  ");
		printf("          %s Rest for eternity\n", choice == 1 ? "->" : "  ");

		key = getch();

		if (key == 0 || key == -32)
		{
			key = getch();
			if (key == 72)
			{
				choice = (choice + 1) % 2;
			}
			else if (key == 80)
			{
				choice = (choice + 1) % 2;
			}
		}
		else if (key == 13)
		{
			if (choice == 0)
			{
				reincarnate(player);
				return main();
			}
			else if (choice == 1)
			{
				restForEternity();
				exit(0);
			}
		}
	}
}

void abandonQuest()
{
	printf("\nYou have chosen to abandone the journey.");
	getch();
	printf("\nSomehow breaking the cycle.");
	getch();
	printf("\nBut were you fulfilled?");
	getch();
	playerAlive = 0;
}

int main()
{
	while (playerAlive)
	{
		switch (currentChapter)
		{
		case 1:
			chapter1P1();
			break;
		case 2:
			chapter1P2();
			break;
		case 3:
			finale();
			break;
		}
		if (playerAlive == 0)
		{
			deathScreen(&player);
		}
	}
	printf("Gamme over");
	return 0;
}
