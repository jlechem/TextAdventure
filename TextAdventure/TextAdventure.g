// define a grammer called TitextAdventure
grammar TextAdventure;

// a sentence is VERB ARITCLE(0 or more) NOUN
// LOOK AT THE X
// PICK UP THE 
// LOOK X
// LOOK
sentence: VERB ARTICLE? NOUN? AND? sentence?

// what can a verb be? This is our list
VERB: 'enter' | 'north' | 'south' | 'east' | 'west' | 'northwest' | 'northeast' | 'southwest' | 'southeast' | 'n' | 's' | 'e' | 'w' | 'nw' | 'ne' | 'sw' | 'se' | 'look' | 'l' | 'examine' | 'take' | 'drop' | 'quit' | 'q' | 'exit' | 'lick' | 'suck' | 'jump' | 'sleep' | 'rest' | 'hum' | 'sing' | 'dance' | 'dive' | 'clean' | 'move' | 'clear' | 'cls' | 'inventory' | 'i' | 'kill' | 'fight' | 'wear' | 'wield' | 'talk' | 'say' | 'speak' | 'tell' |  'go' | 'move' | 'north east' | 'north west' | 'south east' | 'south west' ;

ARTICLE: 'the' | 'an' | 'a' | 'at' | 'under' | 'with' | 'to';

AND: 'and' ;

NOUN: (a-zA-Z)+ ;

WHITESPACE: ( '\t' | ' ' | '\r' | '\n'| '\u000C' )+ -> skip;