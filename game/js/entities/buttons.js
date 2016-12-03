/**
 * UI Objects
 */

game.UI = game.UI || {};

/**
 * a basic button control
 */
game.UI.UnitAdd = me.GUI_Object.extend({
    /**
     * constructor
     */
    init: function(x, y, color, label, action, unit) {
        this._super(me.GUI_Object, "init", [ x, y, {
            image: game.texture,
            region : "addButton",
            unitName: action,  //string
            color: color,
            unit:unit
        } ]);

        // offset of the two used images in the texture
        this.unclicked_region = game.texture.getRegion("addButton");
        this.clicked_region = game.texture.getRegion("addButtonPushed");

        this.anchorPoint.set(0, 0);
        this.setOpacity(1);

        this.font = new me.Font("Arial", 10, "white");
        this.font.textAlign = "left";
        this.font.textBaseline = "middle";

        this.label = label;
        this.unitName = action;
        this.unit = unit;

        //this.parent = me.game.getParentContainer(this);

        // only the parent container is a floating object
        this.floating = false;

    },

    /**
     * function called when the object is clicked on
     */
    onClick : function (/* event */) {
        this.offset.setV(this.clicked_region.offset);
        // account for the different sprite size
        this.pos.y += this.height - this.clicked_region.height ;
        this.height = this.clicked_region.height;
        this.action();

        // don't propagate the event
        return false;
    },

    /**
     * function called when the pointer button is released
     */
    onRelease : function (/* event */) {
        this.offset.setV(this.unclicked_region.offset);
        // account for the different sprite size
        this.pos.y -= this.unclicked_region.height - this.height;
        this.height = this.unclicked_region.height;
        // don't propagate the event
        return false;
    },

    draw: function(renderer) {
        this._super(me.GUI_Object, "draw", [ renderer ]);
        this.font.draw(renderer,
            this.label,
            this.pos.x + this.width / 2,
            this.pos.y + this.height / 2
        );
    },
    action: function(){

            var parent = me.game.getParentContainer(this);
            parent.building.addUnitQ(this.unitName, parent.building.activeQ);

    }
});
/**
 * A Button to remove units
 *
 */
game.UI.UnitRemove = me.GUI_Object.extend({
    /**
     * constructor
     */
    init: function(x, y, label) {
        this._super(me.GUI_Object, "init", [ x, y, {
            image: game.texture,
            region : "deleteButton"
        } ]);

        // offset of the two used images in the texture
        this.unclicked_region = game.texture.getRegion("deleteButton");
        this.clicked_region = game.texture.getRegion("deleteButtonPushed");

        this.anchorPoint.set(0, 0);
        this.setOpacity(1);

        //font
        this.font = new me.Font("Arial", 10, "white");
        this.font.textAlign = "left";
        this.font.textBaseline = "middle";

        this.label = label; //Text

        //Acces to the building
        this.parent = me.game.getParentContainer(this);

        // only the parent container is a floating object
        this.floating = false;
    },

    /**
     * function called when the object is clicked on
     */
    onClick : function (/* event */) {
        this.offset.setV(this.clicked_region.offset);
        // account for the different sprite size
        this.pos.y += this.height - this.clicked_region.height ;
        this.height = this.clicked_region.height;

        var parent = me.game.getParentContainer(this);
        //remove the last unit in the queue
        parent.building.removeUnitQ(parent.building.q.length-1);

        //return a portion of the players gold


        //parent.spawnUnit(this.action);
        // don't propagate the event
        return false;
    },

    /**
     * function called when the pointer button is released
     */
    onRelease : function (/* event */) {
        this.offset.setV(this.unclicked_region.offset);
        // account for the different sprite size
        this.pos.y -= this.unclicked_region.height - this.height;
        this.height = this.unclicked_region.height;
        // don't propagate the event
        return false;
    },

    draw: function(renderer) {
        this._super(me.GUI_Object, "draw", [ renderer ]);
        this.font.draw(renderer,
            this.label,
            this.pos.x + this.width / 2,
            this.pos.y + this.height / 2
        );
    }
});

game.UI.QueueSelector = me.GUI_Object.extend({
    /**
     * constructor
     */
    init: function(x, y, label, index, activeQ, building) {
        this._super(me.GUI_Object, "init", [ x, y, {
            image: game.texture,
            region : "blankButton",
            building:building
        } ]);

        // offset of the two used images in the texture
        this.unclicked_region = game.texture.getRegion("blankButton");
        this.clicked_region = game.texture.getRegion("blankButtonPushed");

        this.anchorPoint.set(0, 0);
        this.setOpacity(1);

        this.font = new me.Font("Arial", 10, "white");
        this.font.textAlign = "left";
        this.font.textBaseline = "middle";

        this.label = label;

        this.index = index;
        this.activeQ = activeQ;

        this.floating = false;

    },

    /**
     * function called when the object is clicked on
     */
    onClick : function (/* event */) {
        this.offset.setV(this.clicked_region.offset);
        // account for the different sprite size
        this.pos.y += this.height - this.clicked_region.height ;
        this.height = this.clicked_region.height;

        var parent = me.game.getParentContainer(this);
        parent.building.activeQ = this.index;

        // don't propagate the event
        return false;
    },

    /**
     * function called when the pointer button is released
     */
    onRelease : function (/* event */) {
        this.offset.setV(this.unclicked_region.offset);
        // account for the different sprite size
        this.pos.y -= this.unclicked_region.height - this.height;
        this.height = this.unclicked_region.height;
        // don't propagate the event
        return false;
    },

    draw: function(renderer) {
        this._super(me.GUI_Object, "draw", [ renderer ]);
        this.font.draw(renderer,
            this.label,
            this.pos.x + this.width / 2 -40,
            this.pos.y + this.height / 2
        );
    }
});

game.UI.developTech = me.GUI_Object.extend({
    /**
     * constructor
     */
    init: function(x, y, color, tech) {
        this._super(me.GUI_Object, "init", [ x, y, {
            image: game.texture,
            region : "blankButton",
            tech: tech
        } ]);

        // offset of the two used images in the texture
        this.unclicked_region = game.texture.getRegion("blankButton");
        this.clicked_region = game.texture.getRegion("blankButtonPushed");

        this.anchorPoint.set(0, 0);
        this.setOpacity(1);

        this.font = new me.Font("Arial", 10, "white");
        this.font.textAlign = "left";
        this.font.textBaseline = "middle";

        this.tech = tech;

        //this.parent = me.game.getParentContainer(this);

        // only the parent container is a floating object
        this.floating = false;

    },

    /**
     * function called when the object is clicked on
     */
    onClick : function (/* event */) {
        this.offset.setV(this.clicked_region.offset);
        // account for the different sprite size
        this.pos.y += this.height - this.clicked_region.height ;
        this.height = this.clicked_region.height;
        //console.log("hitting button " + this.tech);

        //todo make only one click of button allowed

        if(!this.tech.complete && !this.tech.inProcess) {
            this.action(this.tech);
        }else{
            game.data.message= {msgTime: me.timer.getTime(), player:this.player, msg:"This upgrade is already developed ", msgDur: 2, color:"red"};
        }

        return false;
    },

    /**
     * function called when the pointer button is released
     */
    onRelease : function (/* event */) {
        this.offset.setV(this.unclicked_region.offset);
        // account for the different sprite size
        this.pos.y -= this.unclicked_region.height - this.height;
        this.height = this.unclicked_region.height;

        //remove the button
        this.destroy();

        //replace it with text

        // don't propagate the event
        return false;
    },

    draw: function(renderer) {
        this._super(me.GUI_Object, "draw", [ renderer ]);
        this.font.draw(renderer,
            this.tech.name,
            this.pos.x +10,
            this.pos.y + this.height / 2
        );
    },
    //What happens when button is pressed
    action: function(value){

            //add it to the buildings q
            var parent = me.game.getParentContainer(this);
            parent.building.addTechQ(value);
            this.tech.inProcess = true;

    }
})
/*UNFINISHED
game.UI.removeBuilding = me.GUI_Object.extend({
    /!**
     * constructor
     *!/
    init: function(x, y, label) {
        this._super(me.GUI_Object, "init", [ x, y, {
            image: game.texture,
            region : "deleteButton"
        } ]);

        // offset of the two used images in the texture
        this.unclicked_region = game.texture.getRegion("deleteButton");
        this.clicked_region = game.texture.getRegion("deleteButtonPushed");

        this.anchorPoint.set(0, 0);
        this.setOpacity(1);

        //font
        this.font = new me.Font("Arial", 10, "white");
        this.font.textAlign = "left";
        this.font.textBaseline = "middle";

        this.label = label; //Text

        //Acces to the building
        this.parent = me.game.getParentContainer(this);

        // only the parent container is a floating object
        this.floating = false;
    },

    /!**
     * function called when the object is clicked on
     *!/
    onClick : function (/!* event *!/) {
        this.offset.setV(this.clicked_region.offset);
        // account for the different sprite size
        this.pos.y += this.height - this.clicked_region.height ;
        this.height = this.clicked_region.height;

        var parent = me.game.getParentContainer(this);
        //remove the last unit in the queue
        //todo change this so that entities in a queue are emptied out first.
        parent.building.destroy();

        //return a portion of the players gold


        //parent.spawnUnit(this.action);
        // don't propagate the event
        return false;
    },

    /!**
     * function called when the pointer button is released
     *!/
    onRelease : function (/!* event *!/) {
        this.offset.setV(this.unclicked_region.offset);
        // account for the different sprite size
        this.pos.y -= this.unclicked_region.height - this.height;
        this.height = this.unclicked_region.height;
        // don't propagate the event
        return false;
    },

    draw: function(renderer) {
        this._super(me.GUI_Object, "draw", [ renderer ]);
        this.font.draw(renderer,
            this.label,
            this.pos.x + this.width / 2,
            this.pos.y + this.height / 2
        );
    }
});*/
