// define a grammer called TextAdventure
grammar TextAdventure

// we start with a sentence
sentence: VERB? NOUN;

// what can a verb be? This is our list
VERB: 'enter' | 'north' | 'south' | 'east' | 'west' | 'northwest' | 'northeast' | 'southwest' | 'southeast' | 'n' | 's' | 'e' | 'w' | 'nw' | 'ne' | 'sw' | 'se' | 'look' | 'l' | 'examine' | 'take' | 'drop' | 'quit' | 'q' | 'exit' | 'lick' | 'suck' | 'jump' | 'sleep' | 'rest' | 'hum' | 'sing' | 'dance' | 'dive' | 'clean' | 'move' | 'clear' | 'cls' | 'inventory' | 'i' | 'kill' | 'fight';

ARTICLE: 'the' | 'an' | 'a' | 'at' | 'under' ;

NOUN: ('a'..'z')+ ; ;

WHITESPACE: ( '\t' | ' ' | '\r' | '\n'| '\u000C' )+ -> skip;