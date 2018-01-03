// define a grammer called TitextAdventure
grammar TextAdventure;

eval returns [String value]
    :    output= {System.out.println($sentence.VERB + " " + $sentence.NOUN);} 
    ;

// a sentence is VERB ARITCLE(0 or more) NOUN
// LOOK AT THE X
// PICK UP THE 
// LOOK X
// LOOK
sentence: VERB ARTICLE_ONE? ARTICLE_TWO? NOUN? ;

// what can a verb be? This is our list
VERB: 'enter' | 'north' | 'south' | 'east' | 'west' | 'northwest' | 'northeast' | 'southwest' | 'southeast' | 'n' | 's' | 'e' | 'w' | 'nw' | 'ne' | 'sw' | 'se' | 'look' | 'l' | 'examine' | 'take' | 'drop' | 'quit' | 'q' | 'exit' | 'lick' | 'suck' | 'jump' | 'sleep' | 'rest' | 'hum' | 'sing' | 'dance' | 'dive' | 'clean' | 'move' | 'clear' | 'cls' | 'inventory' | 'i' | 'kill' | 'fight' | 'wear' | 'wield' | 'talk' | 'say' | 'speak' | 'tell' |  'go' | 'move' | 'north east' | 'north west' | 'south east' | 'south west' | 'pick' ;
 
ARTICLE_ONE: 'at' | 'under' | 'to' | 'up';

ARTICLE_TWO: 'the' | 'an' | 'a' ;

AND: 'and' ;

NOUN: ('a'..'z'|'A'..'Z')+ ;

WHITESPACE: ( '\t' | ' ' | '\r' | '\n'| '\u000C' )+ -> skip;