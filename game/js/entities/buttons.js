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

/**
 * a basic checkbox control
 */
/*
game.UI.CheckBoxUI = me.GUI_Object.extend({
    /!**
     * constructor
     *!/
    init: function(x, y, texture, on_icon, off_icon, on_label, off_label, action) {

        // call the parent constructor
        this._super(me.GUI_Object, "init", [ x, y, {
            image: texture,
            region : on_icon // default
        } ]);

        // offset of the two used images in the texture
        this.on_offset = texture.getRegion(on_icon).offset;
        this.off_offset = texture.getRegion(off_icon).offset;

        this.anchorPoint.set(0, 0);
        this.setOpacity(0.5);

        this.isSelected = true;

        this.label_on = on_label;
        this.label_off = off_label;

        this.font = new me.Font("kenpixel", 12, "black");
        this.font.textAlign = "left";
        this.font.textBaseline = "middle";

        // only the parent container is a floating object
        this.floating = false;
    },

    /!**
     * function called when the pointer is over the object
     *!/
    onOver : function (/!* event *!/) {
        this.setOpacity(1.0);
    },

    /!**
     * function called when the pointer is leaving the object area
     *!/
    onOut : function (/!* event *!/) {
        this.setOpacity(0.5);
    },

    /!**
     * change the checkbox state
     *!/
    setSelected : function (selected) {
        if (selected) {
            this.offset.setV(this.on_offset);
            this.isSelected = true;
        } else {
            this.offset.setV(this.off_offset);
            this.isSelected = false;
        }
    },

    /!**
     * function called when the object is clicked on
     *!/
    onClick : function (/!* event *!/) {
        this.setSelected(!this.isSelected);
        this.action();
        // don't propagate the event
        return false;
    },

    draw: function(renderer) {
        this._super(me.GUI_Object, "draw", [ renderer ]);

        // save global alpha
        var alpha = renderer.globalAlpha();
        // sprite alpha value
        renderer.setGlobalAlpha(alpha * this.getOpacity());

        this.font.draw(renderer,
            " " + (this.isSelected ? this.label_on : this.label_off),
            this.pos.x + this.width,
            this.pos.y + this.height / 2
        );

        // restore global alpha
        renderer.setGlobalAlpha(alpha);
    }
});
*/

game.UI.QueueSelector = me.GUI_Object.extend({
    /**
     * constructor
     */
    init: function(x, y, img, label, index, activeQ, building) {

        this._super(me.GUI_Object, "init", [ x, y, {
            image: game.texture,
            region : img,
            building : building
        } ]);

        // the two used images in the texture
        this.unclicked_region = game.texture.getRegion(img);
        this.clicked_region = game.texture.getRegion(img+"Pushed");

        this.anchorPoint.set(0, 0);
        this.setOpacity(1);

        //fonts
        this.font = new me.Font("Arial", 10, "white");
        this.font.textAlign = "left";
        this.font.textBaseline = "middle";

        //label displayed on button
        this.label = label;
        this.index = index;
        this.activeQ = activeQ; //set by which button is active
        this.active = false; //

        // only the parent container is a floating object
        this.floating = false;

        this.qbutton = img;

        if(index == this.activeQ)
            this.active = true; // has the button been pressed
        this.changeImage()
    },
    /**
     * function called when the object is clicked on
     */
    onClick : function (/* event */) {
        this.offset.setV(this.clicked_region.offset);
        // account for the different sprite size
        this.pos.y += this.height - this.clicked_region.height ;
        this.height = this.clicked_region.height;

        //update the building with the correct active queue
        //this way when units get added to the Q they have the right queue assignment
        var parent = me.game.getParentContainer(this);
        parent.building.activeQ = this.index;

        this.active = true;

        // don't propagate the event
        //return false;
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
    changeImage: function(){
        if(this.active){
            this.region = this.clicked_region;
        }else{
            this.region = this.unclicked_region;
        }
    }


//     /**
//      * function called when the object is clicked on
//      */
//     onClick : function (/* event */) {
//              // var parent= me.game.getParentContainer(this);
//         //we're going to update visually as well as set which que units will be added to
//         //set the active queue to this button that was pushed
//         this.offset.setV(this.clicked_region.offset);
//         // account for the different sprite size
//         this.pos.y += this.height - this.clicked_region.height ;
//         this.height = this.clicked_region.height;
//
//          this.activeQ= this.index; // update the array on the building itself
//          this.active = true;
//
//         return false;
//     },
//
//     /**
//      * function called when the pointer button is released
//      */
//     onRelease : function (/* event */) {
//         this.offset.setV(this.unclicked_region.offset);
//         // account for the different sprite size
//         this.pos.y -= this.unclicked_region.height - this.height;
//         this.height = this.unclicked_region.height;
//         return false;
//     },
//
//     draw: function(renderer) {
//         this._super(me.GUI_Object, "draw", [ renderer ]);
//         this.font.draw(renderer,
//             this.label,
//             this.pos.x + this.width / 2,
//             this.pos.y + this.height / 2
//         );
//     },
//     changeButton: function(array){
//         for(i=0; i < array.length; i++) {
//             console.log(array[i]);
//             if (array[i] == false) {
//
//                 this.offset.setV(this.inactive_region.offset);
//                 // account for the different sprite size
//                 this.pos.y += this.height - this.inactive_region.height;
//                 this.height = this.active_region.height;
//
//                 //this.active_region = game.texture.getRegion(this.reg+this.index);
//             } else {
//                 this.offset.setV(this.active_region.offset);
//                 // account for the different sprite size
//                 this.pos.y += this.height - this.active_region.height;
//                 this.height = this.active_region.height;
//             }
//         }
//     }
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

        //todo deduct player money msg if not allowed!!!!!
        if (game.data.cashier(this.player, this.tech.cost)){

            //add it to the buildings q
            var parent = me.game.getParentContainer(this);
            parent.building.addTechQ(value);
            this.tech.inProcess = true;
        }

    }
})
game.UI.removeBuilding = me.GUI_Object.extend({
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
        //todo change this so that entities in a queue are emptied out first.
        parent.building.destroy();

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