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
        //this.player = 2;                                                        // player 2 is enemy
        this.waveNumber = game.data.currentwave;                               // save wave number, so that when it changes, an update will be triggered
        this.buildingManager = null;                                            // reference to buildingManagerAI
        this.data = game.dataAI;                                                 // reference to dataAI
        
        this.testSwitch = true;
        this.alwaysUpdate = true;                                               // update when out of viewport
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
            this.buildingManager.build("barracks");                     // command like this to build a building
        }
        
        if (game.dataAI.count("barracks") > 0) {                        // if more than 1 barracks, make a unit
            var building = game.dataAI.getBuilding();
            if (building.percentComplete == 100) {
            
            //    building.addUnitQ("warrior", 0);                      // use this to make units, setting them to where ever
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