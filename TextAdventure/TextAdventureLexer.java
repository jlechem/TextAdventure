// Generated from TextAdventure.g by ANTLR 4.7.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class TextAdventureLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		VERB=1, ARTICLE=2, NOUN=3, WHITESPACE=4;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"VERB", "ARTICLE", "NOUN", "WHITESPACE"
	};

	private static final String[] _LITERAL_NAMES = {
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "VERB", "ARTICLE", "NOUN", "WHITESPACE"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public TextAdventureLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "TextAdventure.g"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\6\u00d6\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2"+
		"\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3\2\3"+
		"\2\3\2\5\2\u00b6\n\2\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\5\3\u00c9\n\3\3\4\6\4\u00cc\n\4\r\4\16\4\u00cd\3\5"+
		"\6\5\u00d1\n\5\r\5\16\5\u00d2\3\5\3\5\2\2\6\3\3\5\4\7\5\t\6\3\2\4\6\2"+
		"ggppuuyy\5\2\13\f\16\17\"\"\2\u0102\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2"+
		"\2\2\t\3\2\2\2\3\u00b5\3\2\2\2\5\u00c8\3\2\2\2\7\u00cb\3\2\2\2\t\u00d0"+
		"\3\2\2\2\13\f\7g\2\2\f\r\7p\2\2\r\16\7v\2\2\16\17\7g\2\2\17\u00b6\7t\2"+
		"\2\20\21\7p\2\2\21\22\7q\2\2\22\23\7t\2\2\23\24\7v\2\2\24\u00b6\7j\2\2"+
		"\25\26\7u\2\2\26\27\7q\2\2\27\30\7w\2\2\30\31\7v\2\2\31\u00b6\7j\2\2\32"+
		"\33\7g\2\2\33\34\7c\2\2\34\35\7u\2\2\35\u00b6\7v\2\2\36\37\7y\2\2\37 "+
		"\7g\2\2 !\7u\2\2!\u00b6\7v\2\2\"#\7p\2\2#$\7q\2\2$%\7t\2\2%&\7v\2\2&\'"+
		"\7j\2\2\'(\7y\2\2()\7g\2\2)*\7u\2\2*\u00b6\7v\2\2+,\7p\2\2,-\7q\2\2-."+
		"\7t\2\2./\7v\2\2/\60\7j\2\2\60\61\7g\2\2\61\62\7c\2\2\62\63\7u\2\2\63"+
		"\u00b6\7v\2\2\64\65\7u\2\2\65\66\7q\2\2\66\67\7w\2\2\678\7v\2\289\7j\2"+
		"\29:\7y\2\2:;\7g\2\2;<\7u\2\2<\u00b6\7v\2\2=>\7u\2\2>?\7q\2\2?@\7w\2\2"+
		"@A\7v\2\2AB\7j\2\2BC\7g\2\2CD\7c\2\2DE\7u\2\2E\u00b6\7v\2\2F\u00b6\t\2"+
		"\2\2GH\7p\2\2H\u00b6\7y\2\2IJ\7p\2\2J\u00b6\7g\2\2KL\7u\2\2L\u00b6\7y"+
		"\2\2MN\7u\2\2N\u00b6\7g\2\2OP\7n\2\2PQ\7q\2\2QR\7q\2\2R\u00b6\7m\2\2S"+
		"\u00b6\7n\2\2TU\7g\2\2UV\7z\2\2VW\7c\2\2WX\7o\2\2XY\7k\2\2YZ\7p\2\2Z\u00b6"+
		"\7g\2\2[\\\7v\2\2\\]\7c\2\2]^\7m\2\2^\u00b6\7g\2\2_`\7f\2\2`a\7t\2\2a"+
		"b\7q\2\2b\u00b6\7r\2\2cd\7s\2\2de\7w\2\2ef\7k\2\2f\u00b6\7v\2\2g\u00b6"+
		"\7s\2\2hi\7g\2\2ij\7z\2\2jk\7k\2\2k\u00b6\7v\2\2lm\7n\2\2mn\7k\2\2no\7"+
		"e\2\2o\u00b6\7m\2\2pq\7u\2\2qr\7w\2\2rs\7e\2\2s\u00b6\7m\2\2tu\7l\2\2"+
		"uv\7w\2\2vw\7o\2\2w\u00b6\7r\2\2xy\7u\2\2yz\7n\2\2z{\7g\2\2{|\7g\2\2|"+
		"\u00b6\7r\2\2}~\7t\2\2~\177\7g\2\2\177\u0080\7u\2\2\u0080\u00b6\7v\2\2"+
		"\u0081\u0082\7j\2\2\u0082\u0083\7w\2\2\u0083\u00b6\7o\2\2\u0084\u0085"+
		"\7u\2\2\u0085\u0086\7k\2\2\u0086\u0087\7p\2\2\u0087\u00b6\7i\2\2\u0088"+
		"\u0089\7f\2\2\u0089\u008a\7c\2\2\u008a\u008b\7p\2\2\u008b\u008c\7e\2\2"+
		"\u008c\u00b6\7g\2\2\u008d\u008e\7f\2\2\u008e\u008f\7k\2\2\u008f\u0090"+
		"\7x\2\2\u0090\u00b6\7g\2\2\u0091\u0092\7e\2\2\u0092\u0093\7n\2\2\u0093"+
		"\u0094\7g\2\2\u0094\u0095\7c\2\2\u0095\u00b6\7p\2\2\u0096\u0097\7o\2\2"+
		"\u0097\u0098\7q\2\2\u0098\u0099\7x\2\2\u0099\u00b6\7g\2\2\u009a\u009b"+
		"\7e\2\2\u009b\u009c\7n\2\2\u009c\u009d\7g\2\2\u009d\u009e\7c\2\2\u009e"+
		"\u00b6\7t\2\2\u009f\u00a0\7e\2\2\u00a0\u00a1\7n\2\2\u00a1\u00b6\7u\2\2"+
		"\u00a2\u00a3\7k\2\2\u00a3\u00a4\7p\2\2\u00a4\u00a5\7x\2\2\u00a5\u00a6"+
		"\7g\2\2\u00a6\u00a7\7p\2\2\u00a7\u00a8\7v\2\2\u00a8\u00a9\7q\2\2\u00a9"+
		"\u00aa\7t\2\2\u00aa\u00b6\7{\2\2\u00ab\u00b6\7k\2\2\u00ac\u00ad\7m\2\2"+
		"\u00ad\u00ae\7k\2\2\u00ae\u00af\7n\2\2\u00af\u00b6\7n\2\2\u00b0\u00b1"+
		"\7h\2\2\u00b1\u00b2\7k\2\2\u00b2\u00b3\7i\2\2\u00b3\u00b4\7j\2\2\u00b4"+
		"\u00b6\7v\2\2\u00b5\13\3\2\2\2\u00b5\20\3\2\2\2\u00b5\25\3\2\2\2\u00b5"+
		"\32\3\2\2\2\u00b5\36\3\2\2\2\u00b5\"\3\2\2\2\u00b5+\3\2\2\2\u00b5\64\3"+
		"\2\2\2\u00b5=\3\2\2\2\u00b5F\3\2\2\2\u00b5G\3\2\2\2\u00b5I\3\2\2\2\u00b5"+
		"K\3\2\2\2\u00b5M\3\2\2\2\u00b5O\3\2\2\2\u00b5S\3\2\2\2\u00b5T\3\2\2\2"+
		"\u00b5[\3\2\2\2\u00b5_\3\2\2\2\u00b5c\3\2\2\2\u00b5g\3\2\2\2\u00b5h\3"+
		"\2\2\2\u00b5l\3\2\2\2\u00b5p\3\2\2\2\u00b5t\3\2\2\2\u00b5x\3\2\2\2\u00b5"+
		"}\3\2\2\2\u00b5\u0081\3\2\2\2\u00b5\u0084\3\2\2\2\u00b5\u0088\3\2\2\2"+
		"\u00b5\u008d\3\2\2\2\u00b5\u0091\3\2\2\2\u00b5\u0096\3\2\2\2\u00b5\u009a"+
		"\3\2\2\2\u00b5\u009f\3\2\2\2\u00b5\u00a2\3\2\2\2\u00b5\u00ab\3\2\2\2\u00b5"+
		"\u00ac\3\2\2\2\u00b5\u00b0\3\2\2\2\u00b6\4\3\2\2\2\u00b7\u00b8\7v\2\2"+
		"\u00b8\u00b9\7j\2\2\u00b9\u00c9\7g\2\2\u00ba\u00bb\7c\2\2\u00bb\u00c9"+
		"\7p\2\2\u00bc\u00c9\7c\2\2\u00bd\u00be\7c\2\2\u00be\u00c9\7v\2\2\u00bf"+
		"\u00c0\7w\2\2\u00c0\u00c1\7p\2\2\u00c1\u00c2\7f\2\2\u00c2\u00c3\7g\2\2"+
		"\u00c3\u00c9\7t\2\2\u00c4\u00c5\7y\2\2\u00c5\u00c6\7k\2\2\u00c6\u00c7"+
		"\7v\2\2\u00c7\u00c9\7j\2\2\u00c8\u00b7\3\2\2\2\u00c8\u00ba\3\2\2\2\u00c8"+
		"\u00bc\3\2\2\2\u00c8\u00bd\3\2\2\2\u00c8\u00bf\3\2\2\2\u00c8\u00c4\3\2"+
		"\2\2\u00c9\6\3\2\2\2\u00ca\u00cc\4c|\2\u00cb\u00ca\3\2\2\2\u00cc\u00cd"+
		"\3\2\2\2\u00cd\u00cb\3\2\2\2\u00cd\u00ce\3\2\2\2\u00ce\b\3\2\2\2\u00cf"+
		"\u00d1\t\3\2\2\u00d0\u00cf\3\2\2\2\u00d1\u00d2\3\2\2\2\u00d2\u00d0\3\2"+
		"\2\2\u00d2\u00d3\3\2\2\2\u00d3\u00d4\3\2\2\2\u00d4\u00d5\b\5\2\2\u00d5"+
		"\n\3\2\2\2\7\2\u00b5\u00c8\u00cd\u00d2\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}