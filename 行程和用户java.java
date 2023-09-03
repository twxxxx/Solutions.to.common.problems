import java.util.ArrayList;
import java.util.List;

public class TravelSchedule {

    private List<Flight> flights;

    public TravelSchedule() {
        this.flights = new ArrayList<>();
    }

    public void addFlight(Flight flight) {
        this.flights.add(flight);
    }

    public List<Flight> getFlights() {
        return this.flights;
    }

    public static void main(String[] args) {
        TravelSchedule schedule = new TravelSchedule();

        Flight flight1 = new Flight("1234567890", "北京", "上海", "2023-07-20", "2023-07-20T10:00:00", "2023-07-20T12:00:00");
        Flight flight2 = new Flight("2345678901", "上海", "北京", "2023-07-21", "2023-07-21T10:00:00", "2023-07-21T12:00:00");

        schedule.addFlight(flight1);
        schedule.addFlight(flight2);

        for (Flight flight : schedule.getFlights()) {
            System.out.println(flight);
        }
    }
}

class Flight {

    private String id;
    private String from;
    private String to;
    private String date;
    private String depart;
    private String arrival;

    public Flight(String id, String from, String to, String date, String depart, String arrival) {
        this.id = id;
        this.from = from;
        this.to = to;
        this.date = date;
        this.depart = depart;
        this.arrival = arrival;
    }

    @Override
    public String toString() {
        return String.format("ID: %s\n起点: %s\n终点: %s\n日期: %s\n起飞时间: %s\n到达时间: %s",
                this.id, this.from, this.to, this.date, this.depart, this.arrival);
    }
}
