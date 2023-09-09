import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        scanner.close();

        String[] tokens = input.split("\\|");
        String phoneNumber = tokens[0];
        int voiceDuration = Integer.parseInt(tokens[1]);
        int voiceRate = Integer.parseInt(tokens[2]);
        int dataUsage = Integer.parseInt(tokens[3]);
        int dataRate = Integer.parseInt(tokens[4]);

        int voiceCost = calculateVoiceCost(voiceDuration, voiceRate);
        int dataCost = calculateDataCost(dataUsage, dataRate);

        int totalCost = voiceCost + dataCost;
        System.out.println(totalCost);
    }

    static int calculateVoiceCost(int duration, int rate) {
        int cost = 0;
        int tmpDuration = duration - 60;
        boolean flag = false;
        if (duration % 60 == 0)
            flag = true;

        if (flag) {
            if (duration <= 60) {
                cost = 0; // 第1分钟免费
            } else if (duration <= 300) {
                cost = (int) Math.ceil((duration - 60) / 60.0 * rate * 1.5 / 10); // 2-5分钟按150%收费
            } else if (duration <= 600) {
                cost = (int) Math.ceil((duration - 300) / 60.0 * rate / 10) + 120; // 6-10分钟按基础费率收费
            } else if (duration <= 1200) {
                cost = (int) Math.ceil((duration - 600) / 60.0 * rate * 0.5 / 10) + 220; // 11-20分钟按50%收费
            } else {
                cost = (int) Math.ceil(((duration - 1200) / 60.0) * rate * 0.2 / 10) + 320; // 21分钟及之后按20%收费
                System.out.println(duration);
            }
        } else {
            if (duration <= 60) {
                cost = 0; // 第1分钟免费
            } else if (duration <= 300) {
                cost = (int) Math.ceil(((duration - 60) / 60.0 + 1) * rate * 1.5 / 10); // 2-5分钟按150%收费
            } else if (duration <= 600) {
                cost = (int) Math.ceil(((duration - 300) / 60.0 + 1) * rate / 10) + 120; // 6-10分钟按基础费率收费
            } else if (duration <= 1200) {
                cost = (int) Math.ceil(((duration - 600) / 60.0 + 1) * rate * 0.5 / 10) + 220; // 11-20分钟按50%收费
            } else {
                cost = (int) Math.ceil((((duration - 1200) / 60.0) + 1) * rate * 0.2 / 10) + 320; // 21分钟及之后按20%收费
                System.out.println(duration);
            }
        }

        return cost;
    }

    static int calculateDataCost(int usage, int rate) {
        int cost = 0;
        if (usage <= 100 * 1024) {
            cost = usage * rate / 100;
        } else if (usage <= 125 * 1024) {
            cost = 100 * 1024 * rate / 100;
        } else if (usage <= 225 * 1024) {
            cost = (int) Math.ceil((usage - 125 * 1024) * rate / 100) + 100 * 1024 * rate / 100;
        } else if (usage <= 325 * 1024) {
            cost = 200 * 1024 * rate / 100;
        } else if (usage <= 625 * 1024) {
            cost = (int) Math.ceil((usage - 325 * 1024) * rate / 100) + 200 * 1024 * rate / 100;
        } else if (usage <= 725 * 1024) {
            cost = 500 * 1024 * rate / 100;
        } else {
            int n = (usage - 725 * 1024) / (200 * 1024);
            int yu = (usage - 500 * 1024) % (200 * 1024);
            if (yu == 0) {
                cost = 500 * 1024 * rate / 100 + n * 100 * 1024 * rate / 100;
            } else if (yu >= 100) {
                cost = 500 * 1024 * rate / 100 + (n + 1) * 100 * 1024 * rate / 100;
            } else if (yu < 100) {
                cost = 500 * 1024 * rate / 100 + n * 100 * 1024 * rate / 100 + yu * 1024 * rate / 100;
            }
        }
        return cost;
    }
}
