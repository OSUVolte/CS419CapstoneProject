

game.Structures = me.Entity.extend({
    /**
     * constructor
     */
    init: function (x, y, settings) {

        //load the general properties
        this.generalProperties();

        // call the super constructor
        this._super(me.Entity, "init", [x, y, settings]);
        this.body.setCollisionMask(me.collision.types.WORLD_SHAPE);
    },
    generalProperties: function(){
        this.q = [];
        this.allowBuild = false;
        this.complete = false;
    },
    onActivateEvent: function () {
        //register on mouse/touch event
        me.input.registerPointerEvent("pointerdown", this, this.onSelect.bind(this));
        me.input.registerPointerEvent("pointerup", this, this.onRelease.bind(this));
        me.input.registerPointerEvent("pointercancel", this, this.onRelease.bind(this));

        // register on the global pointermove event
        // If this causes issus see building_manager for alternative set up
        console.log("onActivate fired");
        this.handler = me.event.subscribe(me.event.POINTERMOVE, this.pointerMove.bind(this));
    },

    /**
     * pointermove function
     */
    pointerMove: function (event) {
        this.hover = false;
        //console.log(event.gameX, event.gameY);
        // move event is global (relative to the viewport)
        if (this.getBounds().containsPoint(event.gameX, event.gameY)) {
            // calculate the final coordinates
            var parentPos = this.ancestor.getBounds().pos;
            var x = event.gameX - this.pos.x - parentPos.x;
            var y = event.gameY - this.pos.y - parentPos.y;

            // the pointer event system will use the object bounding rect, check then with with all defined shapes
            for (var i = this.body.shapes.length, shape; i--, (shape = this.body.shapes[i]);) {
                if (shape.containsPoint(x, y)) {
                    this.hover = true;
                    break;
                }
            }
        }

        if (this.selected) {
            //todo show a menu or status or something

        }

        if (this.hover || this.selected) {
            return false;
        }
    },

    // mouse down function
    onSelect : function (event) {
        if (this.hover === true) {
            // this.grabOffset.set(event.gameX, event.gameY);
            // this.grabOffset.sub(this.pos);
            console.log('selected the new buiding');
            this.selected = true;
            this.displayStatus();
            // don"t propagate the event furthermore
            return false;
        }
        return true;
    },

    // mouse up function
    onRelease : function (/*event*/) {
        this.selected = false;
        // close  building menu

        // don"t propagate the event furthermore
        return false;
    },
    /**
     * Spawns Units of specified type at objects location
     * @param type string of the unit type as defined Classes in Entities.js (i.e. "Warrior" but not "warrior")
     * @param queueAssignment the number of the queue to which the unit should belong
     */
    spawnUnit: function(type, queueAssignment){
       var newUnit =  me.game.world.addChild(me.pool.pull("units", this.pos.x, this.pos.y, eval(type), {
            framewidth: 32,
            frameheight: 32,
            height: this.height,
            width: this.width,
            // direction
            lane: "top",
            qAssignment: queueAssignment, //the units queue assignment

            // which player spawned
            player: 1,
            shapes: [new me.Rect(0, 0, 32, 32)]
        }), 10); //todo not sure about z index
        console.log("Assigned to q", newUnit)
    },
    /**
     * Adds type of element to the Building Queue
     * @param type string of the entity type
     * @param queue snumber fo the queue
     * Returnes true if added
     */
    addUnitQ: function(type, queue){
        //display message
        game.data.message= {msgTime: me.timer.getTime(), msg:"Unit "+type+ "is being built ", msgDur: 2, color:"green"};

        // the time for 1st unit being added
        var time = new Date().getTime();

        //for subsequent units set the time to be higher
        if(this.q.length > 0){
            time = new Date().getTime() + 30*60000; // add 30 minutes
        }

        //an obj with the time it was added and the type of element
        var qObj = {
            time: time,
            type: type,
            queue: queue
        };
        console.log(qObj);
        //don't add if it would go over capacity
        if(this.q.length + 1 <= this.capacity){
            this.q.push(qObj);
            return true;
        }else{
            //display message
            game.data.message= {msgTime: me.timer.getTime(), msg:"Capacity Reached!", msgDur: 10, color:"red"};
        }

        return false;
    },
    /**
     * Removes a building element from the queue
     * @param index index to be removed from the queue
     * returns true if removed.
     */
    removeUnitQ: function(index){
        //make sure it decreased by one
        if(this.q.length > 0){

            //remove it from somewhere in the array
            if(index+1 < this.capacity) {
                this.q.splice(index, 1);
            }

            //if the index of the removed element was the first
            ///we need to update the time or its bug city!
            if(index == 0){
                time = new Date().getTime();
                this.q[0].time = time;
            }

            curLength = this.q.length;
            return this.q.length == curLength - 1;

        }
        return false
    },
    /**
     * Gets the Amount of time until the next Unit will spawn
     * @param q
     */
    tNext: function(q){


    },

    /**
     * Actions to be taken when the unit build is complete
     * @param dt the current time
     * @param cb a call back function of what's to be done when it's complete
     */
    unitComplete: function(ctime){
        var ubt = 100000; //set crazy high for fun!
        //only do this when when have units in the queue
        if(this.q.length > 0){

            //get the first units type
            var unit = this.q[0].type;
            var unitQ = this.q[0].queue;

            ubt = eval(unit).buildTime;

            //console.log((ctime, ctime - this.q[0].time)/1000, ubt )
            //check if unit is complete
            if(( ctime - this.q[0].time)/1000 >= ubt){

                //display message
                game.data.message= {msgTime: me.timer.getTime(), msg:"Unit Complete", msgDur: 5, color:"green"};

                //remove the first element in the queue
                this.q.shift();

                //spawn the unit
                console.log("spawning", unit.toLowerCase());

                this.spawnUnit(unit, unitQ);

                //update the time of the element in the front
                //so that it begins building
                if(this.q[0]){
                    this.q[0].time = new Date().getTime();
                }
            }
        }
    },
    /**
     * update function
     */
    update: function () {
        //This is all handled by the sub or extending class
        //use mainUpate in each to call standard update functions
    },
    /**
     * Used to define functions that are a part of all buildings but would
     * be overridden by the extender's update function, i.e key presses
     * @param dt
     */
    mainUpdate: function(dt){

        this._super(me.Entity, "update", [dt]);
        var now = new Date().getTime();

        //establish time elapsed since the placement
        this.now = Math.round(new Date().getTime()/1000);
        this.elapsed = this.now - this.est;

        //establish a percent complete
        if(this.elapsed < this.buildTime) {
            this.percentComplete = Math.round(( this.elapsed/this.buildTime)*100);
        }else{
            this.percentComplete = 100;
        }

        //do something when its placed
        if(this.placed){

            //start construction
            if(this.elapsed > this.buildTime){
                this.complete = true;
            }
        }

        //spawn units when time is ready
        this.unitComplete(now);

        //log some state stuff
        if(me.input.isKeyPressed("log")){
            this.logitAll(dt);
        }

        return this._super(me.Entity, 'update', [dt]);
    },
    /**
     * Logging of some specific variables to help with trouble shooting
     */
    logitAll: function(dt){
        console.log("selected: ", this.selected);
        console.log("the queue", this.q);
        console.log("dt", dt);
        console.log();

    },

});

//todo set up collisions on buildings
game.Barracks = game.Structures.extend({
    /**
     * constructor
     */
    init:function (x, y, settings) {

        //call the constructor
        this._super(game.Structures, 'init', [x, y , settings]);
        this.x = x;
        this.y = y;
        this.placed = true;
        this.bldgProperties();
        this.body.addShape(new me.Rect(0,0, settings.width, settings.height));  // add a body shape
        this.renderable = new me.Sprite(0, 0, {image: me.loader.getImage("Barracks")}); //addimage
        console.log(this.x, this.y);
    },
    /**
     * Defines all the properties of the building
     *
     */
    bldgProperties: function(){

        this.buildTime = 5;
        this.percentComplete = 0;
        this.est = Math.round(new Date().getTime()/1000);
        this.functional = false; //starts off as non-functional until build time expires

        //the types of units that this building can build
        this.enabled = {
            type1:true,
            type2: true,
            type3: true  //' etc etc //todo add all unit types
        }; //
        this.upm = 5; //units per minute
        this.capacity = 5;
        this.health = 1000;
        this.cost = 200; //cost for barracks is 500 gold
        this.activeQ = 0; // default is the front
    },
    /**
     * Change the image
     */
    chooseImage: function () {
        //todo make it update its color depending on status (healthy, damaged, working, tobe destroyed etc)
        //this.renderable.addAnimation("building", [0], 5);
        //this.renderable.setCurrentAnimation("neutral");
    },
    /**
     * Set spawn point of the footprint
     * Might want to make it relative to some other entity
     */
    setSpawnPoint : function (dt) {
        //todo make this useable
        //It might be best to offset this point from the buildings - but it will need a check to make sure
        //it doesn't interfere with other buildings...
    },
    /**
     * update the entity
     */
    update : function (dt) {

        //mainUpdate - General functions that are good for all buildings
        this.mainUpdate(dt);

        return this._super(me.Entity, "update", [dt])
    },
    /**
     * collision handler
     * (called when colliding with other objects)
     */
    onCollision : function (response, other) {
        // Make all other objects solid
        return true;
    },
    displayStatus: function(){
        this.panelHeight = 300;
        this.panelWidth =400;
        this.panel = me.game.world.addChild(new game.UI.BuildingStatus(this.x, this.y,  this.panelWidth, this.panelHeight, "Barracks Menu", this));

        if(this.enabled.type1 && this.complete){
            this.panel.addChild(new game.UI.UnitAdd(
                20, 40,
                "white",
                "Add Warrior",
                "warrior"// default
            ),110);
        }
        if(this.enabled.type2 && this.complete) {
            this.panel.addChild(new game.UI.UnitAdd(
                20, 90,
                "white",
                "Add Slime", // default
                "slime"
            ), 110);
        }
        if(this.enabled.type3 && this.complete) {
            this.panel.addChild(new game.UI.UnitAdd(
                20, 140,
                "white",
                "Add Rogue", // default
                "rogue"
            ), 110);
        }
        if(this.q.length > 0 && this.complete) {
            this.panel.addChild(new game.UI.UnitRemove(
                20, 190,
                "Remove Unit" // default
            ), 110);
        }

       //Generate 3 buttons for 3 queues
       for(i=0; i < 3; i++){
           this.addQueueButtons(i)

       }

        return this.panel;

        //add the new buttons to a group so that we can track which is currently active
        //and use this to set behaviors and change the display
    },
    addQueueButtons: function (index){
        var xCoor = 20+(50*index);
        var img = "reg"+index;
        //change the image depending if the button is the active queue

        if(this.activeQ == index){
            img = "reg"+index+"Pushed";
        }
        this.panel.addChild(new game.UI.QueueSelector(
            xCoor, this.panelHeight-60,
            img, //img name
            "", // default
            index, // index of this button
            this.activeQ,
            this
        ), 110);
    }

});

game.Armory = game.Structures.extend({
    /**
     * constructor
     */
    init:function (x, y, settings) {

        //call the constructor
        this._super(game.Structures, 'init', [x, y , settings]);
        this.x = x;
        this.y = y;
        this.placed = true;
        this.bldgProperties();
        this.body.addShape(new me.Rect(0,0, settings.width, settings.height));  // add a body shape
        this.renderable = new me.Sprite(0, 0, {image: me.loader.getImage("TechCenter")}); //addimage
        console.log(this.x, this.y);
    },
    /**
     * Defines all the properties of the building
     *
     */
    bldgProperties: function(){

        this.buildTime = 60;
        this.percentComplete = 0;
        this.est = Math.round(new Date().getTime()/1000);
        this.functional = false; //starts off as non-functional until build time expires

        //the types of  tech that this building can build
        this.enabled = {
            type1:true,
            type2: false,
            type3: false  //' etc etc
        };
        this.health = 1000;
        this.cost = 700;
    },
    /**
     * Change the image
     */
    chooseImage: function () {
        //todo make it update its color depending on status (healthy, damaged, working, tobe destroyed etc)
        //this.renderable.addAnimation("building", [0], 5);
        //this.renderable.setCurrentAnimation("neutral");
    },
    /**
     * Set spawn point of the footprint
     * Might want to make it relative to some other entity
     */
    setSpawnPoint : function (dt) {
        //todo make this useable
        //It might be best to offset this point from the buildings - but it will need a check to make sure
        //it doesn't interfere with other buildings...
    },
    /**
     * update the entity
     */
    update : function (dt) {
        //Update functions of our game objects will always receive a delta time (in milliseconds).
        // It's important to pass it along to our parent's class update.
        //setting the time for the building
        this._super(me.Entity, "update", [dt]);

        //mainUpdate - General functions that are good for all buildings
        this.mainUpdate(dt);

        return this._super(me.Entity, "update", [dt]);
    },
    /**
     * collision handler
     * (called when colliding with other objects)
     */
    onCollision : function (response, other) {
        // Make all other objects solid
        return true;
    },
    displayStatus: function(){
        this.panel = me.game.world.addChild(new game.UI.BuildingStatus(this.x, this.y,  400, 300, "Tech Center Menu", this));

        if(this.enabled.type1){
            this.panel.addChild(new game.UI.developTech(
                20, 40,
                "white",
                "Increase Unit Armor",
                "inc_base"
            ),110);
        }
        if(this.enabled.type2) {
            this.panel.addChild(new game.UI.developTech(
                20, 90,
                "white",
                "Increase Unit Health", // default
                "inc_health"
            ), 110);
        }
        if(this.enabled.type3) {
            this.panel.addChild(new game.UI.developTech(
                20, 140,
                "white",
                "Increase Armor (Level Scaling) ", // Scale factor will increase according to level
                "inc_sf"
            ), 110);
        }

        //add the new buttons to a group so that we can track which is currently active
        //and use this to set behaviors and change the display
    }

});




