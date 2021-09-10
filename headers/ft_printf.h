#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int	minus;
	int	zero;
}	t_flags;

typedef struct s_format
{
	t_flags		flags;
	int			width;
	int			precision;
	char		type;
}	t_format;

int			ft_printf(const char *format, ...);
int			ft_is_specifier(char c);
int			ft_is_allowed_char(char c);
int			ft_numberlen(long long a);
int			ft_hexnumberlen(long long a);
long long	ft_min(long long a, long long b);
long long	ft_max(long long a, long long b);
int			ft_putchar(char c);
int			ft_putstr(char *str, int precision);
int			ft_putnbr_decimal(long long *a, int precision);
int			ft_putnbr_hex_lowercase(long long a, int precision);
int			ft_putnbr_hex_uppercase(long long a, int precision);
int			ft_putnbr_address(void *address, int precision);
int			ft_putspecifiers(char **format, va_list *argc);

int			ft_output_zeros(int a);
int			ft_output_spaces(int a);
int			ft_output_percent(void);
int			ft_output_char(t_format *print_format, char c);
int			ft_output_string(t_format *print_format, char *str);
int			ft_output_decimal(t_format *print_format, long long a);
int			ft_output_address(t_format *print_format, void *address);
int			ft_output_specifiers(va_list *argc, t_format *print_format);
int			ft_output_hexadecimal_lowercase(t_format *print_format,
				unsigned long long a);
int			ft_output_hexadecimal_uppercase(t_format *print_format,
				unsigned long long a);

int			ft_fill_flags(char *format,
				t_format *print_format, int *offset);
int			ft_fill_specifiers(char *format,
				t_format *print_format, int *offset);
int			ft_fill_width(char *format, va_list *argc,
				t_format *print_format, int *offset);
int			ft_fill_precision(char *format, va_list *argc,
				t_format *print_format, int *offset);

#endif