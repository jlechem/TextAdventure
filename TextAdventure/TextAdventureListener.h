
// Generated from TextAdventure.g by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "TextAdventureParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by TextAdventureParser.
 */
class  TextAdventureListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSentence(TextAdventureParser::SentenceContext *ctx) = 0;
  virtual void exitSentence(TextAdventureParser::SentenceContext *ctx) = 0;


};

