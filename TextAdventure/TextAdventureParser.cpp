
// Generated from TextAdventure.g by ANTLR 4.7.1


#include "TextAdventureListener.h"

#include "TextAdventureParser.h"


using namespace antlrcpp;
using namespace antlr4;

TextAdventureParser::TextAdventureParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

TextAdventureParser::~TextAdventureParser() {
  delete _interpreter;
}

std::string TextAdventureParser::getGrammarFileName() const {
  return "TextAdventure.g";
}

const std::vector<std::string>& TextAdventureParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& TextAdventureParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SentenceContext ------------------------------------------------------------------

TextAdventureParser::SentenceContext::SentenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TextAdventureParser::SentenceContext::NOUN() {
  return getToken(TextAdventureParser::NOUN, 0);
}

tree::TerminalNode* TextAdventureParser::SentenceContext::VERB() {
  return getToken(TextAdventureParser::VERB, 0);
}

tree::TerminalNode* TextAdventureParser::SentenceContext::ARTICLE() {
  return getToken(TextAdventureParser::ARTICLE, 0);
}


size_t TextAdventureParser::SentenceContext::getRuleIndex() const {
  return TextAdventureParser::RuleSentence;
}

void TextAdventureParser::SentenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TextAdventureListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSentence(this);
}

void TextAdventureParser::SentenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TextAdventureListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSentence(this);
}

TextAdventureParser::SentenceContext* TextAdventureParser::sentence() {
  SentenceContext *_localctx = _tracker.createInstance<SentenceContext>(_ctx, getState());
  enterRule(_localctx, 0, TextAdventureParser::RuleSentence);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(3);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TextAdventureParser::VERB) {
      setState(2);
      match(TextAdventureParser::VERB);
    }
    setState(6);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TextAdventureParser::ARTICLE) {
      setState(5);
      match(TextAdventureParser::ARTICLE);
    }
    setState(8);
    match(TextAdventureParser::NOUN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> TextAdventureParser::_decisionToDFA;
atn::PredictionContextCache TextAdventureParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN TextAdventureParser::_atn;
std::vector<uint16_t> TextAdventureParser::_serializedATN;

std::vector<std::string> TextAdventureParser::_ruleNames = {
  "sentence"
};

std::vector<std::string> TextAdventureParser::_literalNames = {
};

std::vector<std::string> TextAdventureParser::_symbolicNames = {
  "", "VERB", "ARTICLE", "NOUN", "WHITESPACE"
};

dfa::Vocabulary TextAdventureParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> TextAdventureParser::_tokenNames;

TextAdventureParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x6, 0xd, 0x4, 0x2, 0x9, 0x2, 0x3, 0x2, 0x5, 0x2, 0x6, 0xa, 0x2, 
    0x3, 0x2, 0x5, 0x2, 0x9, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x2, 
    0x2, 0x3, 0x2, 0x2, 0x2, 0x2, 0xd, 0x2, 0x5, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x6, 0x7, 0x3, 0x2, 0x2, 0x5, 0x4, 0x3, 0x2, 0x2, 0x2, 0x5, 0x6, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x8, 0x3, 0x2, 0x2, 0x2, 0x7, 0x9, 0x7, 0x4, 0x2, 
    0x2, 0x8, 0x7, 0x3, 0x2, 0x2, 0x2, 0x8, 0x9, 0x3, 0x2, 0x2, 0x2, 0x9, 
    0xa, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb, 0x7, 0x5, 0x2, 0x2, 0xb, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x5, 0x8, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

TextAdventureParser::Initializer TextAdventureParser::_init;
