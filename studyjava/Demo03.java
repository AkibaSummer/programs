import java.util.Date;

public class Demo03{
    public static void main(String[] args){
        
    }
}

class Shape{
    private String color;
    private boolean filled;
    private Date createDate;
    private static int numberOfObjects;
    public Shape(){
        color = "Black";
        filled = false;
        createDate = new Date();
    }
    public String getColor(){
        return color;
    }
    public void setColor(String color_){
        color=color_;
    }
    public void setFilled(boolean filled){
        this.filled=filled;
    }
    public Date getCreateData(){
        return createDate;
    }
}