package project1;

import javafx.animation.KeyFrame;
import javafx.animation.KeyValue;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.util.Duration;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Line;
import javafx.scene.text.Font;

public class Racing_car extends Application {
	int t1=10,t2=10,t3=10,t4=10;
	Timeline timeline=new Timeline();
	ImageView image1=new ImageView(new Image("https://document.silentselene.com/index.php?user/publicLink&fid=854ea-f89pMegLHn3RUurYzlK6xsoe20KBRzUIsmIqtXAL-3HOq4rF_dhQG_MKVBjnp1jvQr9MEelh04IwrEXsAnDhlDmUQ442mudM1fSpKoIQ&file_name=/car.png"));
	ImageView image2=new ImageView(new Image("https://document.silentselene.com/index.php?user/publicLink&fid=854ea-f89pMegLHn3RUurYzlK6xsoe20KBRzUIsmIqtXAL-3HOq4rF_dhQG_MKVBjnp1jvQr9MEelh04IwrEXsAnDhlDmUQ442mudM1fSpKoIQ&file_name=/car.png"));
	ImageView image3=new ImageView(new Image("https://document.silentselene.com/index.php?user/publicLink&fid=854ea-f89pMegLHn3RUurYzlK6xsoe20KBRzUIsmIqtXAL-3HOq4rF_dhQG_MKVBjnp1jvQr9MEelh04IwrEXsAnDhlDmUQ442mudM1fSpKoIQ&file_name=/car.png"));
	ImageView image4=new ImageView(new Image("https://document.silentselene.com/index.php?user/publicLink&fid=854ea-f89pMegLHn3RUurYzlK6xsoe20KBRzUIsmIqtXAL-3HOq4rF_dhQG_MKVBjnp1jvQr9MEelh04IwrEXsAnDhlDmUQ442mudM1fSpKoIQ&file_name=/car.png"));
	@Override
	public void start(Stage primaryStage) {
		primaryStage.setHeight(300);
		primaryStage.setWidth(800);
		primaryStage.show();

		Pane root = new Pane();
		addLabel(root);
		addLine(root);
		addTextField(root);
		
		image1.relocate(0, 60);
		image2.relocate(0, 120);
		image3.relocate(0, 180);
		image4.relocate(0, 240);
		
		image1.setFitHeight(100);
		image2.setFitHeight(100);
		image3.setFitHeight(100);
		image4.setFitHeight(100);
		
		root.getChildren().addAll(image1,image2,image3,image4);
//		Button btn = new Button();	
//		btn.setText("hahha");
//		btn.setOnAction(e->{
//			System.out.println("Fuck");
//			btn.setText(btn.getText()+"fuck");
//			root.getChildren().add(new Button("Fuck"));
//		});
		
		
		//root.getChildren().add(btn);
		
		Scene scene=new Scene(root, 300, 800);
		textChanged();
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	public static void main (String args[]) {
		launch(args);
		System.out.println("Finish!");
	}
	
	public void addLabel(Pane root) {
		for (int i=0;i<4;i++) {
			root.getChildren().add(newLabel("Car "+(i+1)+":",i*200,10,new Font("Arial",30)));
		}
	}
	
	public void addLine(Pane root) {
		for (int i=1;i<=4;i++) {
			root.getChildren().add(new Line(0,i*60,800,i*60));
		}
	}
	
	public void addTextField(Pane root) {
		root.getChildren().addAll(
				newTextField("10",100,5,new Font("Arial",25),1),
				newTextField("10",300,5,new Font("Arial",25),2),
				newTextField("10",500,5,new Font("Arial",25),3),
				newTextField("10",700,5,new Font("Arial",25),4)
		);
	}
	
	private void textChanged() {
//		timeline.setCycleCount(Timeline.INDEFINITE);
		
		KeyValue kv1p=new KeyValue(image1.xProperty(),0);
		KeyValue kv2p=new KeyValue(image2.xProperty(),0);
		KeyValue kv3p=new KeyValue(image3.xProperty(),0);
		KeyValue kv4p=new KeyValue(image4.xProperty(),0);
		KeyFrame kf1p=new KeyFrame(Duration.millis(0), kv1p);
		KeyFrame kf2p=new KeyFrame(Duration.millis(0), kv2p);
		KeyFrame kf3p=new KeyFrame(Duration.millis(0), kv3p);
		KeyFrame kf4p=new KeyFrame(Duration.millis(0), kv4p);
		
		KeyValue kv1=new KeyValue(image1.xProperty(),700);
		KeyValue kv2=new KeyValue(image2.xProperty(),700);
		KeyValue kv3=new KeyValue(image3.xProperty(),700);
		KeyValue kv4=new KeyValue(image4.xProperty(),700);
		KeyFrame kf1=new KeyFrame(Duration.millis(t1*100), kv1);
		KeyFrame kf2=new KeyFrame(Duration.millis(t2*100), kv2);
		KeyFrame kf3=new KeyFrame(Duration.millis(t3*100), kv3);
		KeyFrame kf4=new KeyFrame(Duration.millis(t4*100), kv4);
		timeline.getKeyFrames().clear();
		timeline.getKeyFrames().addAll(kf1,kf2,kf3,kf4,kf1p,kf2p,kf3p,kf4p);
		timeline.stop();
		//timeline.setDelay(Duration.millis(1000));
		timeline.play();	
		
	}
	
	private Label newLabel(String text,double x,double y,Font font) {
		Label temp=new Label(text);
		temp.relocate(x, y);
		temp.setFont(font);
		return temp;
	}
	
	private TextField newTextField(String text,double x,double y,Font font,int t) {
		TextField temp = new TextField(text);
		temp.relocate(x, y);
		temp.setFont(font);
		temp.setPrefSize(90, 50);
		switch (t){
		case 1:temp.setOnAction(e->{
			t1=Integer.parseInt((temp.getText()));
			textChanged();
		});break;
		case 2:temp.setOnAction(e->{
			t2=Integer.parseInt((temp.getText()));
			textChanged();
		});break;
		case 3:temp.setOnAction(e->{
			t3=Integer.parseInt((temp.getText()));
			textChanged();
		});break;
		case 4:temp.setOnAction(e->{
			t4=Integer.parseInt((temp.getText()));
			textChanged();
		});break;
		}
		return temp;
	}
}
