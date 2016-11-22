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
    init: function(x, y, color, label, action) {
        this._super(me.GUI_Object, "init", [ x, y, {
            image: game.texture,
            region : "addButton",
            action: action,  //string
            color: color
        } ]);

        // offset of the two used images in the texture
        this.unclicked_region = game.texture.getRegion("addButton");
        this.clicked_region = game.texture.getRegion("addButtonPushed");

        this.anchorPoint.set(0, 0);
        this.setOpacity(1);

        this.font = new me.Font("Arial", 10, this.color);
        this.font.textAlign = "left";
        this.font.textBaseline = "middle";

        this.label = label;
        this.action = action;

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
        console.log("hitting button " + this.action);

        var parent = me.game.getParentContainer(this);
        parent.building.addUnitQ(this.action, parent.building.activeQ);

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
 * image of a unit button to cancel build and display
 *
 */
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
        this.font = new me.Font("Arial", 12, "black");
        this.font.textAlign = "center";
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
game.UI.CheckBoxUI = me.GUI_Object.extend({
    /**
     * constructor
     */
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

    /**
     * function called when the pointer is over the object
     */
    onOver : function (/* event */) {
        this.setOpacity(1.0);
    },

    /**
     * function called when the pointer is leaving the object area
     */
    onOut : function (/* event */) {
        this.setOpacity(0.5);
    },

    /**
     * change the checkbox state
     */
    setSelected : function (selected) {
        if (selected) {
            this.offset.setV(this.on_offset);
            this.isSelected = true;
        } else {
            this.offset.setV(this.off_offset);
            this.isSelected = false;
        }
    },

    /**
     * function called when the object is clicked on
     */
    onClick : function (/* event */) {
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

game.UI.QueueSelector = me.GUI_Object.extend({
    /**
     * constructor
     */
    init: function(x, y, img, label, index, activeQ) {
        this._super(me.GUI_Object, "init", [ x, y, {
            image: game.texture,
            region : img
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

        me.game.repaint();

        this.active = true;

        // don't propagate the event
        //return false;
        return false;
    },
    update: function (){
        if(this.activeQ == this.index){
            this.offset.setV(this.clicked_region.offset);
            return true;
        }else{
            this.offset.setV(this.unclicked_region.offset);
        }
        return false
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
    init: function(x, y, color, label, action) {
        this._super(me.GUI_Object, "init", [ x, y, {
            image: game.texture,
            region : "blankButton",
            action: action  //string
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
        this.action = action;

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
        console.log("hitting button " + this.action);

        var parent = me.game.getParentContainer(this);
        parent.building.addUnitQ(this.action, parent.building.activeQ);

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