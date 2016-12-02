/**
 * Enemy AI
 */
// controlled via timer
// will do things based on difficulty
 
game.EnemyAI = me.Entity.extend({
    init: function(x, y, settings) {
        // call the constructor
        this._super(me.Entity, 'init', [x, y, settings]);
        
        this.alwaysUpdate = true;
        
        // anything else
        this.waveNumber = game.data.currentwave;                                 // save wave number, so that when it changes, an update will be triggered
        this.buildingManager = null;                                             // reference to buildingManagerAI
        this.data = game.dataAI;                                                 // reference to dataAI
        
        this.testSwitch = true;
        this.alwaysUpdate = true;                                               // update when out of viewport
        
        if (game.data.mode == "hard") {
            this.spawnTime = 6000;                                              // spawn every 6 seconds instead of 8 for hardmode
        } else {
            this.spawnTime = 8000;                                              // spawn every 8 seconds
        }
    },
    
    update : function(dt) {
        // first find buildingManagerAI in pool
        if (this.buildingManager == null) {
            this.buildingManager = findEntityByName("P2_build_area");
           console.log(this.data);
        }
        
        // if no buildings, build barracks. buildingManager will handle amount of gold
        if (this.testSwitch == true) {
            this.testSwitch = false;
            this.buildingManager.isPlacing = true;
            this.buildingManager.build("barracks");                                                                 // command like this to build a building

        } if (this.testSwitch == false && this.buildingManager.buildings < 2 && game.data.mode == "hard") {         // hardmode i like to build 2 buildings cuz im cool
            this.buildingManager.isPlacing = true;
            this.buildingManager.build("barracks");                     
        }
        
        //randomly queue a unit every 8 seconds
        if(game.data.lastAIspawnTime + this.spawnTime <= game.data.gametime) {
            game.data.lastAIspawnTime = game.data.gametime;
            if (game.dataAI.count("barracks") > 0) {                        // if more than 1 barracks, make a unit
                for (var i = 0; i < game.dataAI.count("barracks"); i++) {
                    var building = game.dataAI.getBuilding("barracks");
                    if (building.percentComplete == 100) {
                        if (game.data.mode == "easy") {
                            var randomUnit = Math.floor((Math.random() * 8) + 1);                       // easy mode, more chances to spawn slimes
                        } else {
                            var randomUnit = Math.floor((Math.random() * 4) + 1);                       // hard mode, never spawns slimes ever again    
                        }
                        switch(randomUnit) {
                            case 1:
                                if(building.q.length < building.capacity && game.dataAI.playergold > warrior.cost){
                                    building.addUnitQ("warrior", 0);
                                }
                                break;
                            case 2:
                                if(building.q.length < building.capacity && game.dataAI.playergold > minotaur.cost){
                                    building.addUnitQ("minotaur", 0);
                                }
                                break;
                            case 3:
                                if(building.q.length < building.capacity && game.dataAI.playergold > wizard.cost){
                                    building.addUnitQ("wizard", 0);
                                }
                                break;
                            case 4:
                                if(building.q.length < building.capacity && game.dataAI.playergold > rogue.cost){
                                    building.addUnitQ("rogue", 0);
                                }
                                break;
                            case 5:
                                if(building.q.length < building.capacity && game.dataAI.playergold > slime.cost){
                                    building.addUnitQ("slime", 0);
                                }
                                break;
                            default:
                                if(building.q.length < building.capacity && game.dataAI.playergold > slime.cost){
                                    building.addUnitQ("slime", 0);
                                }
                                break;
                        }
                    }
                }
                return true;
            }
        }

        return (this._super(me.Entity, 'update', [dt]));
    },

    onCollision : function(response, other) {
    
        return true;
    }
});


function findEntityByName(name) {
    for (var i = 0; i < me.game.world.children.length; i++) {
        if (me.game.world.children[i].name === name) {
            return me.game.world.children[i];
        }
    }
    
    return null;
}