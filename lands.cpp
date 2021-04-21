#include "lands.h"
#include "player.h"
using namespace std;

Land* getRandomLand(){
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);
    
    switch(selection){
        case LAKE:
            return new Lake;
            break;
        case FOREST:
            return new Forest;
            break;
        case DESERT:
            return new Desert;
            break;
        case MOUNTAINS:
            return new Mountains;
            break;
        case TOWN:
            return new Town;
            break;
        case SWAMP:
           return new Swamp;
           break;
        case TUNDRA:
            return new Tundra;
            break;
        default:
            return new Lake;
            break;
    }
    
}

//Lake
string Lake::getShortDescription(){
    return "lake";
}

string Lake::getLongDescription(){
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p){
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
}

//Forest
string Forest::getShortDescription(){
    
    return "forest";
}

string Forest::getLongDescription(){
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p){
    string description = "You forage for berries but find nothing.";
    
    int chance = rand() % 100;
    
    // Chance to find berries
    if(chance > 50){
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance to get mauled by bear
    if(chance < 10 && chance > 5){
        description = "You are attacked by a hungry bear in the woods!";
        p.setHealth(p.getHealth() - 1);
    }
    
    // Chance to get double mauled
    if(chance < 5){
        description = "You are attacked by two very large bears!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    
    
    return description;
}

//Desert
string Desert::getShortDescription(){
    return "desert";
}

string Desert::getLongDescription(){
    return "You arrive in a extremely hot, dry desert";
}

string Desert::visit(Player& p){
    string description = "The heat of the desert makes you dehydrated.";
    
    if(p.getThirst() > 0){
        p.setThirst(p.getThirst() - 1);
    }

    return description;
}

//Mountains
string Mountains::getShortDescription(){
    return "Mountains";
}

string Mountains::getLongDescription(){
    return "After a long climb you reach the summit of the mountain.";
}

string Mountains::visit(Player& p){
    int chance = rand() % 100;
    string description;
    
    if(chance > 25){
        description = "After the long climb you realize you are thirsty!";
    } else {
        description = "At the peak of the mountain you find a treasure chest!";
        p.setGold(p.getGold() + 10);
    }
    
    return description;
}

//Town
string Town::getShortDescription(){
    return "Town";
}

string Town::getLongDescription(){
    return "You enter the town and head to the market.";
}

string Town::visit(Player& p){
    string description;
    if(p.getGold() > 0){
        if(p.getHealth() <  Player::DEFAULT_HEALTH){
            int dif =  Player::DEFAULT_HEALTH - p.getHealth();
            if(p.getGold() > dif){
                p.setHealth( Player::DEFAULT_HEALTH);
                p.setGold(p.getGold() - dif);
                description = "You payed some of your gold to heal";
            } else {
                p.setHealth(p.getHealth() + p.getGold());
                description = "You payed all of your gold to heal";
                p.setGold(0);
                
            }
        }
    } else {
        description = "You have no money to spend in the market.";
    }
    
    
    return description;
}

//Swamp
string Swamp::getShortDescription(){
    return "Swamp";
}

string Swamp::getLongDescription(){
    return "You enter the swamp and run into a witch.";
}

string Swamp::visit(Player& p){
    int chance = rand() % 100;
    string description;
    
    if(chance > 50){
        description = "The witch was in a good mood, she decided to heal you!";
        if(p.getHealth() < Player::DEFAULT_HEALTH){
            p.setHealth(p.getHealth() + 1);
        }
    } else {
        description = "The witch was in a bad mood, she stabs you!";
        p.setHealth(p.getHealth() - 1);
    }
    
    return description;
}

//Tundra
string Tundra::getShortDescription(){
    return "Tundra";
}

string Tundra::getLongDescription(){
    return "You enter the the tundra, it is very cold.";
}

string Tundra::visit(Player& p){
    int chance = rand() % 100;
    string description;
    
    if(chance > 50){
        description = "You get caught in a blizard and take damage!";
        p.setHealth(p.getHealth() - 1);
    } 
    
    return description;
}

//Jungle
string Jungle::getShortDescription(){
    return "Jungle";
}

string Jungle::getLongDescription(){
    return "You enter the jungle, it has trees.";
}

string Jungle::visit(Player& p){
    int chance = rand() % 100;
    string description;
    
    if(chance < 6){
        description = "You fall into a pit fall trap and just die. The end, better luck next time chump";
        p.setHealth(0);
    } else {
        description = "You find a coconut and releive your hunger and thirst";
        p.setHunger(p.getHunger() + 1);
        p.setThirst(p.getThirst() + 1);
    }
    
    return description;
}