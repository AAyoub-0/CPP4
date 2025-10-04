# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 15:52:18 by aboumall          #+#    #+#              #
#    Updated: 2025/10/04 18:51:47 by aboumall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG = 0

HEADERS = AMateria.hpp Character.hpp Cure.hpp \
			ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp Ice.hpp

TARGET = materias

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp AMateria.cpp Character.cpp Cure.cpp \
		MateriaSource.cpp Ice.cpp
OBJ = $(SRC:.cpp=.o)

ifeq ($(DEBUG), 1)
	CXXFLAGS += -DDEBUG=1
else
	CXXFLAGS += -DDEBUG=0
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
