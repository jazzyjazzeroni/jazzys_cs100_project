gameManager()
{
    GameMap gameMap;
    MainCharactor player;
    Inventory inventory;

    void gameStart()
    {
        while
        {
            takeAction();
        }
    }

    void takeAction()
    {
        char action;
        cin >> action;
        if(i)
        {
            inventory.open(player); // todo
        }
        if(wasd)
        {
            x,y = (player.move(action))
            Object enconter = gmaemap[y][x]
            if(enconter.type == "charactor")
            {
                player.attact(gamemap, x, y);
            }
            else if(encounter.type == 'sword')
            {
                player.addSword(gamemap, x, y) // todo
            }
            else if(enconter.type == "possion")
            {
                inventory.add(game, x, y)
            }
           //  check if plahyer is dead
           if(dead)
           {
            end game
           }
        }
    }
}



GameMap
{
    int height, width;
    int numGoblin;
    int goblinKilled;
    vector <Object> mapMatrix;
    GameMap(vector<vector<int>> initMatrix, w, h)
    {
        mapMatrix
        for y in range h:
            for x in range w;
                if(initMatrix[y][x] == 0)
                {
                    mapMatrix[y][x] = Object()
                }
                if(initMatrix[y][x] == 1)
                {
                    mapMatrix[y][x] = Sword(10, "swmall sword")
                }
                if(initMatrix[y][x] == 2)
                {  mapMatrix[y][x] = Sword(15, "bigger sword")
               
                }
              
    }
    void init();
    void killgoblin(x,y)
    {
        set goblin[y][x] = Object
        goblinkilledp ++
    }
}

Object
{
    type : "charactor" | "sword" | "possion" |"empty"
    Object()
    {
        type = empty
    }
}

Charactor 
{
    damage
    health
    max health
    type
    power
    +getHealth(): getter  
    +setHealth(int): setter  void
    +isAlive():  bool
    +attack(Character &): virtual  void
    +takeDamage(double): void (virtual)
    +getPower() :string
    +setPower(string)
}

Goblin : charactor
{
    type:"goblin"
}

MainCharactor : Character
{
    int x,y
    heal(int)
    Sword sword;
    move(actionm gamemap&)
    {
        if w{
            newx, newy = x, (y-1)%map.getheight()
        }
        x, y = newx, newy;
        return gamemap[y][x]
    }
    getPosition
    {
        return x, y
    }

    attact(gamemap, x, y)
    {
        charactpr = gamemap[y][x]
        if(charactpr is goblin)
        {
            if(power is not equal)
            {
                calculate the attach
                expectDamage, expectAttact
                character.takeDamage(experectAttact)
                this.takeDamage(experectDamage)
                if(charator.dead)
                {
                    gamemap.killGoblin(x,y)
                }
            }
        }
    }
    addsword(gamemap, x, y)
    {
        print(current sword)
        print(new sword)
        int switch;
        cin >> switch
        if switch{
            this.sword = newsword
        }
    }
}

Inventory{
    potion_10 = 0
    potion_15 = 0
    potion_20 = 0

    add(gamemap, x, y)
     {
        item = gamemap[y]x;
        if(item.posionanme == 10)
        {
            possion_10 ++
        }
     }
     open(player)
     {
        printout all the stuff
        if has possionp
        player.heal()
     }
}