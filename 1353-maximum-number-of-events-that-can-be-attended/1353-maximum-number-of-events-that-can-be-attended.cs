public class Solution {
    public int MaxEvents(int[][] events) {
        events = events.OrderBy(x => x[1]).ThenBy(x => x[0]).ToArray();
        var calendar = new int[events.Last()[1] + 1];
        var prevStartDay = -1;
        var prevBookDay = -1;
        foreach(var evt in events) {
            var startDay = evt[0];
            if (prevStartDay == evt[0]) startDay = prevBookDay + 1;
            prevStartDay = evt[0];
            for(var i = startDay; i <= evt[1] && i < calendar.Length; i++) {
                if (calendar[i] == 0) {
                    calendar[i] = 1;
                    prevBookDay = i;
                    break;
                }
            }
        }
        return calendar.Count(x => x != 0);
    }
}
