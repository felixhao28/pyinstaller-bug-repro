import PyInstaller.__main__

PyInstaller.__main__.run("main.py -y -F -n tk --hidden-import=pkg_resources.py2_warn".split(" "))