#include "main.h"

// === ゲームの初期化関数 ===
void init_game(void) {
    srand((unsigned int)time(NULL));

    // タイトル表示
    puts("");
    printf(CYAN BOLD "╔═══════════════════════════════════╗\n" RESET);
    printf(CYAN BOLD "║        🎮 じゃじゃんけん 🎮       ║\n" RESET);
    printf(CYAN BOLD "╚═══════════════════════════════════╝\n" RESET);
    puts("");
}

// === 手を文字列に変換する関数 ===
const char *get_hand_name(hand_t hand) {
    static const char *hand_names[HAND_COUNT] = {"✊ グー  ", "✌️ チョキ",
                                                 "✋ パー  "};
    return (hand_names[hand]);
}

// === 正しい入力を受け取る関数 ===
hand_t get_user_hand(void) {
    int input;

    printf(YELLOW "✋ じゃんけんの手を選んでください:\n" RESET);
    for (int i = 0; i < HAND_COUNT; i++) {
        printf("   %s%d: %s%s\n", BOLD, i, get_hand_name((hand_t)i), RESET);
    }
    puts("");
    printf(BLUE "➤ 入力: " RESET);

    if (scanf("%d", &input) != 1) {
        printf(RED "❌ 無効な入力です。\n" RESET);
        return INVALID_HAND;
    }

    if (input < ROCK || input > PAPER) {
        printf(RED "❌ 0, 1, 2の数字を入力してください\n" RESET);
        return INVALID_HAND;
    }

    return (hand_t)input;
}

// === 相手のランダムな手を生成する関数 ===
hand_t get_computer_hand(void) {
    return (rand() % HAND_COUNT);
}

// === じゃんけんの結果を判定する関数 ===
result_t judge_result(hand_t player_hand, hand_t computer_hand) {
    return (player_hand - computer_hand + ADJUSTMENT_VALUE) % HAND_COUNT;
}

// === じゃんけんをプレイする関数 ===
void play_janken(hand_t player_hand, hand_t computer_hand) {
    puts("");
    printf(MAGENTA "🎯 じゃんけん、");
    fflush(stdout);
    usleep(GAME_SPEED * 1000000);
    printf("ぽん！\n" RESET);

    result_t result = judge_result(player_hand, computer_hand);

    usleep(GAME_SPEED * 1000000);
    puts("");
    printf("┌─────────────────────────────────┐\n");
    printf("│         🎊 結果発表 🎊          │\n");
    printf("├─────────────────────────────────┤\n");
    printf("│ %sあなた%s:       %s         │\n", CYAN BOLD, RESET,
           get_hand_name(player_hand));
    printf("│ %sコンピュータ%s: %s         │\n", MAGENTA BOLD, RESET,
           get_hand_name(computer_hand));
    printf("└─────────────────────────────────┘\n");
    puts("");

    switch (result) {
    case DRAW:
        printf(YELLOW BOLD "🤝 あいこです！\n" RESET);
        break;
    case LOSE:
        printf(RED BOLD "😭 あなたの負けです...\n" RESET);
        break;
    case WIN:
        printf(GREEN BOLD "🎉 あなたの勝ちです！ 🎊\n" RESET);
        break;
    }
    puts("");
}

int main(void) {

    init_game();

    hand_t player_hand = get_user_hand();
    if (player_hand == INVALID_HAND) {
        return (1);
    }

    hand_t computer_hand = get_computer_hand();
    play_janken(player_hand, computer_hand);

    return (0);
}