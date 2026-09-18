/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
let c;
var createCounter = function(init) {
    c=init;
    return obj = {
         increment(){
            init += 1;
            return init;
        },
         decrement(){
            init -= 1;
            return init;
        },
         reset(){
            init = c;
            return init;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */