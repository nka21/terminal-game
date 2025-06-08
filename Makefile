# ターミナルゲーム集

# ゲームの種類
GAMES = number_guessing \
		jajanken
GAME_DIRS = $(foreach game,$(GAMES),$(game))

# カラー配色
BLUE = \033[34m
GREEN = \033[32m
YELLOW = \033[33m
CYAN = \033[36m
RESET = \033[0m
BOLD = \033[1m

# デフォルトでコマンド集を見れるように
all: list

# コマンド集
list:
	@echo "$(CYAN)$(BOLD)🎮 ターミナルゲーム集 🎮$(RESET)"
	@echo "$(BLUE)════════════════════════════════════════$(RESET)"
	@echo "$(GREEN)ゲームコマンド:$(RESET)"
	@for game in $(GAMES); do \
		echo "  $(YELLOW)make $$game$(RESET) - $$game を開始"; \
	done
	@echo ""
	@echo "$(GREEN)その他コマンド:$(RESET)"
	@echo "  $(YELLOW)make clean$(RESET) - Clean all games"

# オブジェクト削除
clean:
	@echo "$(CYAN)$(BOLD)🧹 全ゲームをクリーン中...$(RESET)"
	@for game in $(GAMES); do \
		echo "$(YELLOW)$$game をクリーン中...$(RESET)"; \
		cd $$game && $(MAKE) clean && cd ..; \
		echo ""; \
		echo ""; \
	done
	@echo "$(GREEN)$(BOLD)✅ 全ゲームのクリーンが完了しました！$(RESET)"

number_guessing:
	@echo "$(CYAN)🎯 数字予想ゲームを開始中...$(RESET)"
	@cd number_guessing && $(MAKE) run

jajanken:
	@echo "$(CYAN)✊ じゃんけんゲームを開始中...$(RESET)"
	@cd jajanken && $(MAKE) run

# phonyターゲット宣言
.PHONY: all list clean $(GAMES)