package project5;

import java.util.Random;
import javafx.application.*;
import javafx.event.*;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.scene.image.*;
import javafx.scene.layout.*;
import javafx.scene.text.*;

class calc{
	public static double calcInfix(String text) {
		int num=0;
		for (int i=text.length()-1;i>=0;i--) {
			if (text.charAt(i)==' ')text=text.substring(0,i)+text.substring(i+1);
			else if (text.charAt(i)==')')num++;
			else if (text.charAt(i)=='(')num--;
			else if (num==0&&text.charAt(i)=='+')return calcInfix(text.substring(0,i))+calcInfix(text.substring(i+1));
			else if (num==0&&text.charAt(i)=='-')return calcInfix(text.substring(0,i))-calcInfix(text.substring(i+1));
		}
		for (int i=text.length()-1;i>=0;i--) {
			if (text.charAt(i)==')')num++;
			else if (text.charAt(i)=='(')num--;
			else if (num==0&&text.charAt(i)=='*')return calcInfix(text.substring(0,i))*calcInfix(text.substring(i+1));
			else if (num==0&&text.charAt(i)=='/')return calcInfix(text.substring(0,i))/calcInfix(text.substring(i+1));
		}
		if (text.charAt(0)=='('&&text.charAt(text.length()-1)==')')return calcInfix(text.substring(1, text.length()-1));
		return Double.parseDouble(text);
	}
	public static String calc24Point(int... input) {
		final char symbal[]=new char[]{'+','-','*','/'};
		for (int a=0;a<4;a++) 
			for (int b=0;b<4;b++) 
				if (b!=a)
				for (int c=0;c<4;c++) 
					if (c!=b&&c!=a)
					for (int d=0;d<4;d++) 
						if (d!=a&&d!=b&&d!=c) {
							for (int i=0;i<64;i++) {
								if (calcInfix("(("+input[a]+symbal[i/16]+input[b]+')'+symbal[i/4%4]+input[c]+')'+symbal[i%4]+input[d])==24.0)
									return "(("+input[a]+symbal[i/16]+input[b]+')'+symbal[i/4%4]+input[c]+')'+symbal[i%4]+input[d];
								else if (calcInfix("("+input[a]+symbal[i/16]+input[b]+')'+symbal[i/4%4]+'('+input[c]+symbal[i%4]+input[d]+')')==24.0)
									return "("+input[a]+symbal[i/16]+input[b]+')'+symbal[i/4%4]+'('+input[c]+symbal[i%4]+input[d]+')';
							}
						}			
		return "No Solution!";
	}
}

public class Twenty_Four_Point_Game extends Application {
	private ImageView newImageView(double x,double y) {
		ImageView temp=new ImageView(new Image(getClass().getResource("card/backCard.png").toString()));
		temp.relocate(x, y);
		temp.setPreserveRatio(true);
		temp.setFitWidth(180);
		return temp;
	}
	private Button newButton(String text,double x,double y,EventHandler<ActionEvent> event) {
		Button temp=new Button(text);
		temp.relocate(x, y);
		temp.setFont(new Font("Arial",30));
		temp.setOnAction(event);;
		return temp;		
	}
	private Label newLabel(String text,double x,double y) {
		Label temp=new Label(text);
		temp.relocate(x, y);
		temp.setFont(new Font("Arial",30));
		return temp;
	}
	private TextField newTextField(String text,double x,double y,double w,boolean editable) {
		TextField temp=new TextField(text);
		temp.relocate(x, y);
		temp.setFont(new Font("Arial",25));
		temp.setPrefSize(w, 55);
		temp.setEditable(editable);
		return temp;
	}
	private int t[]=new int[] {0,0,0,0};
	private ImageView images[]=new ImageView[] {newImageView(25,80),newImageView(215,80),newImageView(405,80),newImageView(595,80)};
	private TextField texts[]=new TextField[] {newTextField("Please Refresh",300,10,310,false),newTextField("",340,335,295,true)};
	private Button buttons[]=new Button[] {
			newButton("Find a Solution",25,10,e->{
				texts[0].setText(calc.calc24Point(t[0]%13+1,t[1]%13+1,t[2]%13+1,t[3]%13+1));
				}),
			newButton("Refresh",620,10,e->{
				for (int i=0;i<4;i++) 
					images[i].setImage(new Image(getClass().getResource("card/"+((t[i]=new Random().nextInt(52))+1)+".png").toString()));
			}),
			newButton("Verify",645,335,e->{
				String temp[]=('*'+texts[1].getText()).split("\\D+");
				if (temp.length==5)
				for (int i=0;i<4;i++)
					for (int j=1;j<=4;j++) 
						if (t[i]%13+1==Integer.parseInt(temp[j])) {temp[j]="0";break;}
				int sum=0;
				for (int i=1;i<temp.length;i++)
					sum+=Integer.parseInt(temp[i]);
				if (temp.length!=5||sum!=0) texts[0].setText("Number mismatch.");
				else if (calc.calcInfix(texts[1].getText())==24.0) texts[0].setText("You are a genius!");
				else texts[0].setText("You are foolish!");
			})};
	public void start(Stage primaryStage) {
		primaryStage.setHeight(400);
		primaryStage.setWidth(800);
		primaryStage.show();
		Pane root = new Pane();
		root.getChildren().addAll(images[0],images[1],images[2],images[3],newLabel("Enter an experssion:",25,350)
				,buttons[0],buttons[1],buttons[2],texts[0],texts[1]);
		primaryStage.setScene(new Scene(root, primaryStage.getHeight(), primaryStage.getWidth()));
	}
	public static void main (String args[]) {
		launch(args);
	}
}