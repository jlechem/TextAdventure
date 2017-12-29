// Generated from TextAdventure.g by ANTLR 4.7.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link TextAdventureParser}.
 */
public interface TextAdventureListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link TextAdventureParser#sentence}.
	 * @param ctx the parse tree
	 */
	void enterSentence(TextAdventureParser.SentenceContext ctx);
	/**
	 * Exit a parse tree produced by {@link TextAdventureParser#sentence}.
	 * @param ctx the parse tree
	 */
	void exitSentence(TextAdventureParser.SentenceContext ctx);
}