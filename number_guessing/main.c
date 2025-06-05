#include "main.h"

int get_user_pred(void) {
    int pred;

    printf(CYAN BOLD "🎯 数字予想ゲーム 🎯\n" RESET);
    printf(YELLOW "0~9の数字を入力してください: " RESET);

    if (scanf("%d", &pred) != 1) {
        printf(RED "❌ 無効な入力です\n" RESET);
        return -1;
    }

    if (pred < MIN || pred > MAX) {
        printf(RED "❌ %d~%dの数字で入力してください\n" RESET, MIN, MAX);
        return -1;
    }

    return (pred);
}

size_t run_pred_game(int target, double game_speed) {
    size_t count = 0;

    printf(BLUE "═══════════════════════════════════════\n" RESET);
    printf(MAGENTA "⏱️  判定速度: " BOLD "%.1f秒" RESET MAGENTA "に1度\n" RESET,
           game_speed);
    printf(GREEN "🎮 スタート!! 予測値: " BOLD "%d" RESET GREEN " 📍\n" RESET,
           target);
    printf(BLUE "═══════════════════════════════════════\n" RESET);

    while (1) {
        count++;
        usleep(game_speed * 1000000);
        int number = rand() % 10;

        if (number == target) {
            printf(GREEN BOLD "🎉 %zu回目: %d (的中!) 🎉\n" RESET, count,
                   number);
            break;
        }

        printf(YELLOW "⚡ %zu回目: " BOLD "%d" RESET "\n", count, number);
    }

    printf(BLUE "═══════════════════════════════════════\n" RESET);
    printf(GREEN BOLD "✨ ゲーム終了! ✨\n" RESET);
    printf(BLUE "═══════════════════════════════════════\n" RESET);

    return (count);
}

void print_result(size_t result) {
    printf(CYAN BOLD "🏆 結果発表 🏆\n" RESET);
    printf(GREEN "🎯 " BOLD "%zu回目" RESET GREEN "で一致しました!!\n" RESET,
           result);
}

void init_game(void) {
    srand((unsigned int)time(NULL));
}

int main(void) {
    printf(BOLD CYAN "\n");
    puts("  ██████╗  █████╗ ███╗   ███╗███████╗");
    puts("  ██╔════╝ ██╔══██╗████╗ ████║██╔════╝");
    puts("  ██║  ███╗███████║██╔████╔██║█████╗  ");
    puts("  ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ");
    puts("  ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗");
    puts("   ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝");
    printf(RESET "\n");

    init_game();

    int prediction = get_user_pred();
    if (prediction == -1) {
        return (1);
    }

    size_t result = run_pred_game(prediction, GAME_SPEED);
    print_result(result);

    return (0);
}