BUILD_DIR := build
MAIN_EXEC := PasswordCracker
CMAKE := cmake
MAKE := make

$(BUILD_DIR):
	@echo "Создание директории $(BUILD_DIR)"
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/Makefile: $(BUILD_DIR)
	@echo "Запуск CMake..."
	cd $(BUILD_DIR) && $(CMAKE) ..

all: $(BUILD_DIR)/Makefile
	@echo "Сборка проекта..."
	cd $(BUILD_DIR) && $(MAKE)

clean:
	@echo "Очистка..."
	rm -rf $(BUILD_DIR)

.PHONY: all run clean build_and_run
