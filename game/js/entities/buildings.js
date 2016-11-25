

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
        this.functional = false;
        this.player =1;

        //properties for health bar
        this.hpBarCurrent = new me.Font("Verdana", 11, "green");
        this.hpBarCurrent.lineWidth = 1;
        this.hpBarCurrent.strokeStyle = new me.Color(0, 0, 0, 50);
        // player 1 is green hp bar, 2 is red hp bar
        if (this.player == 1) {
            this.hpBarCurrent.fillStyle = new me.Color(0, 255, 0, 50);
        } else {
            this.hpBarCurrent.fillStyle = new me.Color(255, 0, 0, 50);
        }
        this.hpBarMax = new me.Font("Verdana", 11, "black");
        this.hpBarMax.alpha = 0.5;

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
        }), 10);
        console.log("Assigned to q", newUnit)
    },
    /**
     * Adds type of element to the Building Queue
     * @param type string of the entity type
     * @param queue snumber fo the queue
     * Returnes true if added
     */
    addUnitQ: function(unit, queue){
        //display message
        game.data.message= {msgTime: me.timer.getTime(), msg:"Unit "+unit+" is being built", msgDur: 2, color:"green"};

        // the time for 1st unit being added
        var time = new Date().getTime();

        //for subsequent units set the time to be higher
        if(this.q.length > 0){
            time = new Date().getTime() + 30*60000; // add 30 minutes
        }

        //an obj with the time it was added and the type of element
        var qObj = {
            time: time,
            type: unit,
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
     * Adds a tech a Queue
     * @param techObj string of the entity type
     * Returnes true if added
     */
    addTechQ: function(techObj){
        //display message
        game.data.message= {msgTime: me.timer.getTime(), msg:""+techObj.name+ " is being Developed", msgDur: 2, color:"green"};

        // the time for 1st unit being added
        techObj.startTime = me.timer.getTime();

        //don't add if it would go over capacity
        if(this.q.length + 1 <= this.capacity){
            this.q.push(techObj);
            console.log("tech Q", this.q);
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
            if(index == 0 && this.q.length > 0){
                time = new Date().getTime();
                this.q[0].time = time;
            }

            curLength = this.q.length;
            return this.q.length == curLength - 1;

        }
        return false
    },
    /**
     * Removes a building element from the Tech queue
     * @param index index to be removed from the queue
     * returns true if removed.
     */
    removeTechQ: function(index){
        //make sure it decreased by one
        if(this.q.length > 0){

            //remove it from somewhere in the array
            if(index+1 < this.capacity) {
                this.q.splice(index, 1);
            }

            //if the index of the removed element was the first
            ///we need to update the time or its bug city!
            if(index == 0 && this.q.length > 0){
                time = me.timer.getTime();
                this.q[0].startTime = time;
            }

            curLength = this.q.length;
            return this.q.length == curLength - 1;

        }
        return false
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

            //check if unit is complete
            if(( ctime - this.q[0].time)/1000 >= ubt){

                //display message
                game.data.message= {msgTime: me.timer.getTime(), msg:"Unit Complete ", msgDur: 5, color:"green"};

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

            //start construction and set when done
            if(this.elapsed > this.buildTime){
                this.complete = true;

            }

            //Disable building if not healthy enough
            if(this.health > 0.5*this.fullHealth){
                this.functional = true;
            }
        }

        //log some state stuff
        if(me.input.isKeyPressed("log")){
            this.logitAll(dt);
        }

        return this._super(me.Entity, 'update', [dt]);
    },
    draw : function(renderer) {
        var unitHp = "";
        var percent = this.health / this.fullHealth * 100;

        if (percent >= 80) {
            unitHp += "▄"
        }
        if (percent >= 60) {
            unitHp += "▄"
        }
        if (percent >= 40) {
            unitHp += "▄"
        }
        if (percent >= 20) {
            unitHp += "▄"
        }
        if (percent >= 0) {
            unitHp += "▄"
        }

        this._super(me.Entity, "draw", [renderer]);
        this.hpBarMax.draw(renderer, "▄▄▄▄▄", this.pos.x+50, this.pos.y-20);
        this.hpBarCurrent.draw(renderer, unitHp, this.pos.x+50, this.pos.y-20);
        this.hpBarCurrent.drawStroke(renderer, "▄▄▄▄▄", this.pos.x+50, this.pos.y-20);
    },
    /**
     * Logging of some specific variables to help with trouble shooting
     */
    logitAll: function(dt){
        console.log("selected: ", this.selected);
        console.log("the queue", this.q);
        console.log("dt", dt);
        console.log("building health", this.health);
        console.log("percentComplete", this.percentComplete);
        console.log("functional", this.functional);

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
    },
    /**
     * Defines all the properties of the building
     *
     */
    bldgProperties: function(){

        this.buildTime = 5;
        this.percentComplete = 0;
        this.est = Math.round(new Date().getTime()/1000);

        //the types of units that this building can build
        this.enabled = {
            type1:true,
            type2: true,  //set these via game conditionals
            type3: true  //' etc etc //todo add all unit types
        }; //
        this.upm = 5; //units per minute
        this.capacity = 5;
        this.fullHealth = 1000;
        this.health = this.fullHealth;
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

        var now = new Date().getTime();

        //spawn units when time is ready
        this.unitComplete(now);

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

        if(this.enabled.type1 && this.complete && this.functional){
            this.panel.addChild(new game.UI.UnitAdd(
                20, 45,
                "white",
                "Add Warrior",
                "warrior",// default
                warrior
            ),110);
        }
        if(this.enabled.type2 && this.complete && this.functional) {
            this.panel.addChild(new game.UI.UnitAdd(
                20, 80,
                "white",
                "Add Slime", // default
                "slime",
                slime
            ), 110);
        }
        if(this.enabled.type3 && this.complete && this.functional) {
            this.panel.addChild(new game.UI.UnitAdd(
                20, 115,
                "white",
                "Add Rogue", // default
                "rogue",
                rogue
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

game.Armourer = game.Structures.extend({
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
        this.renderable = new me.Sprite(0, 0, {image: me.loader.getImage("Armourer")}); //addimage
    },
    /**
     * Defines all the properties of the building
     *
     */
    bldgProperties: function(){

        this.buildTime = 5;
        this.percentComplete = 0;
        this.est = Math.round(new Date().getTime()/1000);
        this.capacity = 2;
        this.fullHealth = 1000;
        this.health = this.fullHealth;
        this.cost = 700;

        //the types of  tech that this building can build
        this.tech1 = {
            name: "Inc. Armor 25",
            startTime: null, // set when button is pressed
            buildTime: 6,
            action: "inc_base",
            value: 25,
            cost: 100,
            enabled:true,
            complete: false,
            inProcess: false

        };

        this.tech2 = {
            name: "Inc. Health 25",
            startTime: null,
            buildTime: 9,
            action: "inc_health",
            value: 25,
            cost:400,
            enabled:true,
            complete: false,
            inProcess: false

        };

        this.tech3 = {
            name: "Inc. Armor Scaling 1.25",
            startTime: null,
            buildTime: 12,
            action: "inc_sf",
            value: 1.25,
            cost: 1000,
            enabled:true,
            complete: false,
            inProcess: false

        };
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

        //Function watches the techQ, sets enabled when build time is done,
        this.developTech(me.timer.getTime());

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
    /**
     * The Display pop up on the building
     */
    displayStatus: function(){
        this.panel = me.game.world.addChild(new game.UI.BuildingStatus(this.x, this.y,  400, 300, "Armorour  Menu", this));

        if(this.tech1.enabled && this.functional && this.complete){
            this.panel.addChild(new game.UI.developTech(
                20, 40,
                "white", //text color
                this.tech1  // the amount to change
            ),110);
        }
        if(this.tech2.enabled && this.functional && this.complete) {
            this.panel.addChild(new game.UI.developTech(
                20, 90,
                "white",
                this.tech2
            ), 110);
        }
        if(this.tech3.enabled && this.functional && this.complete) {
            this.panel.addChild(new game.UI.developTech(
                20, 140,
                "white",
                this.tech3
            ), 110);
        }

    },

    developTech: function (now) {

        //check front of q for finished tech
        if (this.q.length > 0) {
            if ((now - this.q[0].startTime ) / 1000 >= this.q[0].buildTime) {
                console.log(now, this.q[0].startTime,(now - this.q[0].startTime) / 1000,  this.q[0].buildTime);
                //apply the item
                //Armory applies to all units

                switch (this.q[0].action) {
                    case "inc_base":
                        game.data.defBoost =  game.data.defBoost + this.q[0].value;
                        //send a message
                        game.data.message = {
                            msgTime: me.timer.getTime(),
                            msg: "Armor Boosted by " + this.q[0].value,
                            msgDur: 4,
                            color: "blue"
                        };
                        //mark this tech complete
                        this.q[0].complete = true;

                        break;

                    case "inc_health":
                        game.data.hpBoost = game.data.hpBoost + this.q[0].value;
                        game.data.message = {
                            msgTime: me.timer.getTime(),
                            msg: "Health Boosted by " + this.q[0].value,
                            msgDur: 4,
                            color: "blue"
                        };
                        //mark this tech complete
                        this.q[0].complete = true;

                        break;

                    case "inc_sf":
                        game.data.sfArmor = this.q[0].value;
                        game.data.message = {
                            msgTime: me.timer.getTime(),
                            msg: "Scaling Factor Boosted by " + this.q[0].value,
                            msgDur: 4,
                            color: "blue"
                        };

                        //mark this tech complete
                        this.q[0].complete = true;

                        break;
                }

                //remove it from the q
                this.removeTechQ(0);

                //Let them know what is next in development cycle
                if (this.q.length > 0)
                    game.data.message = {
                        msgTime: me.timer.getTime(),
                        msg: "Now developing " + this.q[0].name,
                        msgDur: 4,
                        color: "blue"
                    };
            }
        }
    }

});

game.Arsenal = game.Structures.extend({
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
        this.renderable = new me.Sprite(0, 0, {image: me.loader.getImage("Arsenal")}); //addimage
    },
    /**
     * Defines all the properties of the building
     *
     */
    bldgProperties: function(){

        this.buildTime = 5;
        this.percentComplete = 0;
        this.est = Math.round(new Date().getTime()/1000);
        this.capacity = 2;
        this.fullHealth = 1000;
        this.health = this.fullHealth;
        this.cost = 700;

        //the types of  tech that this building can build
        this.tech1 = {
            name: "Inc. Attack 25",
            startTime: null, // set when button is pressed
            buildTime: 6,
            action: "inc_base",
            value: 25,
            cost: 100,
            enabled:true,
            complete: false,
            inProcess: false

        };

        this.tech2 = {
            name: "Inc. speed 25",
            startTime: null,
            buildTime: 9,
            action: "inc_speed",
            value: 5,
            cost:400,
            enabled:true,
            complete: false,
            inProcess: false

        };

        this.tech3 = {
            name: "Inc. Attack Scaling 1.25",
            startTime: null,
            buildTime: 12,
            action: "inc_sf",
            value: 1.25,
            cost: 1000,
            enabled:true,
            complete: false,
            inProcess: false
        };
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

        //Function watches the techQ, sets enabled when build time is done,
        this.developTech(me.timer.getTime());

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
    /**
     * The Display pop up on the building
     */
    displayStatus: function(){
        this.panel = me.game.world.addChild(new game.UI.BuildingStatus(this.x, this.y,  400, 300, "Arsenal  Menu", this));

        if(this.tech1.enabled && this.functional && this.complete){
            this.panel.addChild(new game.UI.developTech(
                20, 40,
                "white", //text color
                this.tech1 // the tech that will be applied by te button
            ),110);
        }
        if(this.tech2.enabled && this.functional && this.complete) {
            this.panel.addChild(new game.UI.developTech(
                20, 90,
                "white",
                this.tech2
            ), 110);
        }
        if(this.tech3.enabled && this.functional && this.complete) {
            this.panel.addChild(new game.UI.developTech(
                20, 140,
                "white",
                this.tech3
            ), 110);
        }

    },

    developTech: function (now) {

        //check front of q for finished tech
        if (this.q.length > 0) {
            if ((now - this.q[0].startTime ) / 1000 >= this.q[0].buildTime) {

                //apply the tech
                switch (this.q[0].action) {
                    case "inc_base":
                        game.data.atkBoost =  game.data.atkBoost + this.q[0].value;
                        //send a message
                        game.data.message = {
                            msgTime: me.timer.getTime(),
                            msg: "Attack Boosted by " + this.q[0].value,
                            msgDur: 4,
                            color: "blue"
                        };
                        //mark this tech complete
                        this.q[0].complete = true;

                        //todo deduct player money


                        break;

                    case "inc_health":
                        game.data.speedBoost = game.data.speedBoost+ this.q[0].value;
                        game.data.message = {
                            msgTime: me.timer.getTime(),
                            msg: "Speed Boosted by " + this.q[0].value,
                            msgDur: 4,
                            color: "blue"
                        };
                        //mark this tech complete
                        this.q[0].complete = true;

                        break;

                    case "inc_sf":
                        game.data.sfAtk = this.q[0].value;
                        game.data.message = {
                            msgTime: me.timer.getTime(),
                            msg: "Scaling Factor Boosted by " + this.q[0].value,
                            msgDur: 4,
                            color: "blue"
                        };

                        //mark this tech complete
                        this.q[0].complete = true;

                        break;
                }

                //remove it from the q
                this.removeTechQ(0);

                //Let them know what is next in development cycle
                if (this.q.length > 0)
                    game.data.message = {
                        msgTime: me.timer.getTime(),
                        msg: "Now developing " + this.q[0].name,
                        msgDur: 4,
                        color: "blue"
                    };
            }
        }
    }

});




