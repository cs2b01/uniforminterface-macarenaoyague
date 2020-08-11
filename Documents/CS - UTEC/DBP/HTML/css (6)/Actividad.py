from flask import Flask, render_template, session, request, redirect, url_for
app=Flask(__name__)


@app.route("/gallery/")
def main():
    return render_template('gallery.html')

@app.route("/tictactoe/")
def login():
    return render_template('tictactoe.html')

if __name__=="__main__":
    app.run()
