
// Generated from TextAdventure.g by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "TextAdventureListener.h"


/**
 * This class provides an empty implementation of TextAdventureListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  TextAdventureBaseListener : public TextAdventureListener {
public:

  virtual void enterSentence(TextAdventureParser::SentenceContext * /*ctx*/) override { }
  virtual void exitSentence(TextAdventureParser::SentenceContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

