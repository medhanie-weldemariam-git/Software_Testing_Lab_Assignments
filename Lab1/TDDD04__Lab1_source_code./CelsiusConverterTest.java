package converter;

import java.awt.Component;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenuItem;
import javax.swing.JTextField;

import converter.CelsiusConverter;
import junit.extensions.abbot.ComponentTestFixture;
import junit.extensions.abbot.TestHelper;
import abbot.finder.matchers.ClassMatcher;
import abbot.finder.matchers.JMenuItemMatcher;
import abbot.tester.JButtonTester;
import abbot.tester.JTextComponentTester;

/**
 * Demonstrates testing a simple Swing UI ({@link CelsiusConverter}) with Abbot.
 * 
 * @author Satadip Dutta (original)
 * @author Tom Roche (ported to new-style Abbot, added more tests)
 * @version $Id: CelsiusConverterTest.java,v 1.5 2005/05/06 23:27:16 tlroche Exp
 *          $
 */
public class CelsiusConverterTest extends ComponentTestFixture {

	// for precision testing
	final static int DEFAULT_PRECISION = 0;
	final static int PRECISION2 = 2;
	final static int PRECISION3 = 3;

	private CelsiusConverter cc;
	private JTextField tempCelsius;
	private JButton convertButton;
	private JLabel outputLabel;
	private JLabel inputLabel;

	/*
	 * ,,,
	 */
	
	private JTextComponentTester tt;
	private JButtonTester bt;

	/** For older versions of JUnit. */
	public CelsiusConverterTest(String name) {
		super(name);
	}

	protected void setUp() throws Exception {
		cc = new CelsiusConverter();
		JFrame frame = new JFrame();
		cc.enframe(frame);
		// Display at the current frame's desired size (avoids packing)
		showWindow(frame, null, false);

		// only one JTextField in our UI, so we can just class-match
		tempCelsius = (JTextField) getFinder().find(
				new ClassMatcher(JTextField.class));
		// ditto for the JButton
		convertButton = (JButton) getFinder().find(
				new ClassMatcher(JButton.class));
		// But there's 2 JLabel's in our UI, so we need to add more
		// information
		outputLabel = (JLabel) getFinder().find(new ClassMatcher(JLabel.class) {
			public boolean matches(Component c) {
				String text = CelsiusConverter
						.lookupString("output.label.text");
				return super.matches(c) && ((JLabel) c).getText().equals(text);
			}
		});
		
		//inputlabel for checking celsius output.
		inputLabel = (JLabel) getFinder().find(new ClassMatcher(JLabel.class) {
			public boolean matches(Component c) {
				String text = CelsiusConverter
						.lookupString("input.label.text");
				return super.matches(c) && ((JLabel) c).getText().equals(text);
			}
		});

		/*
		 * YOUR CODE GOES HERE...
		 */

		tt = new JTextComponentTester();
		bt = new JButtonTester();
	}

	public void testNegativeNumber() throws Exception {

		tt.actionEnterText(tempCelsius, "-45"); //$NON-NLS-1$
		bt.actionClick(convertButton);
		assertEquals(CelsiusConverter.fahrenheitOutput(-49, DEFAULT_PRECISION),
				outputLabel.getText());
	}

	public void testBadInput() throws Exception {
		// get default text
		String originalText = outputLabel.getText();
		// nothing should change if the input is not parseable as a double
		tt.actionEnterText(tempCelsius, " HELLO "); //$NON-NLS-1$
		bt.actionClick(convertButton);
		assertTrue("Output changed for bad input", outputLabel.getText()
				.equals(originalText)); //$NON-NLS-1$
	}

	public void testChangePrecision() throws Exception {
		JMenuItem item2 = (JMenuItem) getFinder().find(
				new JMenuItemMatcher(String.valueOf(PRECISION2))); //$NON-NLS-1$

		// the output should update to reflect a higher precision after making
		// a change, even with no new input

		// initial precision is 0
		tt.actionEnterText(tempCelsius, "25.23"); //$NON-NLS-1$
		bt.actionClick(convertButton);

		// now update precision and make sure output fields update too
		tt.actionSelectMenuItem(item2);

		assertEquals(
				"Failed to reflect change in precision", //$NON-NLS-1$
				CelsiusConverter.fahrenheitOutput(77.41, PRECISION2),
				outputLabel.getText());
	}

	public void testHighPrecision() throws Exception {
		JMenuItem item3 = (JMenuItem) getFinder().find(
				new JMenuItemMatcher(String.valueOf(PRECISION3))); //$NON-NLS-1$
		tt.actionSelectMenuItem(item3);
		tt.actionEnterText(tempCelsius, "-45.543"); //$NON-NLS-1$
		bt.actionClick(convertButton);

		assertEquals(
				"Failed to show answer with proper precision", //$NON-NLS-1$
				CelsiusConverter.fahrenheitOutput(-49.977, PRECISION3),
				outputLabel.getText());
	}

	/*
	 * YOUR TEST CASES
	 */
	public void testAbsoluteZero() throws Exception {
		//Test fahrenheit output for a temperature below absolute zero
		tt.actionEnterText(tempCelsius, "-273.16"); //$NON-NLS-1$
		bt.actionClick(convertButton);
		assertEquals(CelsiusConverter.fahrenheitOutput(-459.68, DEFAULT_PRECISION),
				outputLabel.getText());
	}	
	public void testAbsoluteZeroCelsiusOutput() throws Exception {
		//Test celsius output for a temperature below absolute zero
		tt.actionEnterText(tempCelsius, "-273.16"); //$NON-NLS-1$
		bt.actionClick(convertButton);
		assertEquals(CelsiusConverter.celsiusOutput(-273.16, DEFAULT_PRECISION),
				inputLabel.getText());
	}
	public void testCelsiusOutput() throws Exception {
		//Test celsius output for a valid value.
		tt.actionEnterText(tempCelsius, "16"); //$NON-NLS-1$
		bt.actionClick(convertButton);
		assertEquals(CelsiusConverter.celsiusOutput(16, DEFAULT_PRECISION),
				inputLabel.getText());
	}
	
	public void testLookupString() throws Exception {
		//Test to lookup an invalid string.
		String text = CelsiusConverter.lookupString("this.will.not.work");		
		assertEquals(text,"!this.will.not.work!");
	}

	public void testPressEnter() throws Exception {
		// Test to push return button.
		tt.actionEnterText(tempCelsius, "16"); //$NON-NLS-1$
		tt.actionActionMap(tempCelsius, "notify-field-accept");
		assertEquals(CelsiusConverter.celsiusOutput(16, DEFAULT_PRECISION),
				inputLabel.getText());
	}
	
	public void testMain() throws Exception {
		
		CelsiusConverter.main(null);
	}
	
	public static void main(String[] args) {
		/*
		 * junit.textui.TestRunner.main(new String[] {
		 * CelsiusConverterTest.class.getName() });
		 */
		TestHelper.runTests(args, CelsiusConverterTest.class);
	}
}
