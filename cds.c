#include "main.h"
/**
 * cd_dot - changes to parent directory
 * @command: comand passed
 */
void cd_dot(char **command)
{
	char pwd[PATH_MAX];
	char *hold, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);
	set_env("OLDPWD", cp_pwd);
	hold = command[1];
	if (_strcmp(".", hold) == 0)
	{
		set_env("PWD", cp_pwd);
		free(cp_pwd);
		return;
	}
	if (_strcmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_string(cp_strtok_pwd);
	cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _strtok(NULL, "\0");
		if (cp_strtok_pwd != NULL)
			rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("PWD", cp_strtok_pwd);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/");
	}
	free(cp_pwd);
}
/**
 * cd_to - changes to a given directory
 * @command: command passed
 */
void cd_to(char **command)
{
	char pwd[PATH_MAX];
	char *hold, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	hold = command[1];
	if (chdir(hold) == -1)
	{
		perror(callmemaybe);
		return;
	}
	cp_pwd = _strdup(pwd);
	set_env("OLDPWD", cp_pwd);
	cp_dir = _strdup(hold);
	set_env("PWD", cp_dir);

	free(cp_pwd);
	free(cp_dir);

	chdir(hold);
}
/**
 * cd_previous - changes to previous directory
 * @command: command passed
 */
void cd_previous(void)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);

	p_oldpwd = _getenv("OLDPWD", _environ);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _strdup(p_oldpwd);
	set_env("OLDPWD", cp_pwd);
	if (chdir(cp_oldpwd) == -1)
		set_env("PWD", cp_pwd);
	else
		set_env("PWD", cp_oldpwd);
	p_pwd = _getenv("PWD", _environ);

	write(STDOUT_FILENO, p_pwd, _strlen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	chdir(p_pwd);
}
/**
 * cd_to_home - changes to home directory
 * @command: command passed
 */
void cd_to_home(void)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup(pwd);

	home = _getenv("HOME", _environ);
	if (home == NULL)
	{
		set_env("OLDPWD", p_pwd);
		free(p_pwd);
		return;
	}
	if (chdir(home) == -1)
	{
		perror(callmemaybe);
		free(p_pwd);
		return;
	}
	set_env("OLDPWD", p_pwd);
	set_env("PWD", home);
	free(p_pwd);
}
