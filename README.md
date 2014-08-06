C-
==


// // Wish could write code like:
// for = {
//     initialize;
//     while {condition;} {
//         body;
//         increment;
//     }
// }
// // I guess with function pointers, that's possible.
// //... but what's a more elegant scheme for inputs?
// //... in particular, I want to combine:
// //        * array-brackets ("[]") and 
// //        * member-dots (".") and 
// //        * function calls ("()") into
// //    one nice syntax.
// //    Furthermore, when passing chunks of __code__,
// //    I don't want the unnatural burden of communicating our whole state
// //    via the arguments.


// symbol <space> member:
// if member's a symbolic literal, then proceed normally:
linkedlist {prev} = 3 // like C's "linkedlist.prev".
linkedlist {next} = 5

//...but if member's undefined, then use as __input__
plus summand_one summand_two = (summand_one + summand_two)
print plus (linkedlist prev) (linkedlist next) // prints 8.
                                               // doesn't that look like __LISP__?

for initialize condition increment body = {
    initialize;
    while {condition;} { // semicolon ";" __runs__ code contained in "condition".
        body;
        increment;
    }
}
// // C implementation:
// void func_001(void* var_0025, // in this case, func pointers.
//               void* var_0026,
//               void* var_0027,
//               void* var_0028) {
//     (*var_0025)();
//     while((*var_0026)()) {
//         (*var_0028)();
//         (*var_0027)();
//     }
// }


greet = {
    for {i = 0} {i < 52} {i += 1} {
        print "hey"
    }
}

greet; // prints "hey" 52 times.
greet; // another wave of greetings.
