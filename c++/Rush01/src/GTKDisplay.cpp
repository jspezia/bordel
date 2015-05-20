#include "GTKDisplay.hpp"

typedef std::list<GtkWidget *> blist;

static void print_hello (GtkWidget *, gpointer) {
	g_print ("Hello World\n");
}

GTKDisplay::GTKDisplay() {
}

GTKDisplay::GTKDisplay(Sysctl *ctl) : _ctl(ctl) {
}

GTKDisplay::GTKDisplay(GTKDisplay const &) {
}

GTKDisplay::~GTKDisplay() {
}

void GTKDisplay::display(mlist &targets) {
	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *button;//1, *button2, *quit;

	int argc = this->_ctl->getAC();
	char **argv = this->_ctl->getAV();
	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Window");
	grid = gtk_grid_new ();
	gtk_container_add (GTK_CONTAINER (window), grid);
	g_signal_connect (window, "destroy",
			G_CALLBACK (gtk_main_quit), NULL);
	gtk_container_set_border_width (GTK_CONTAINER (window), 300);


	blist butts;
	mlist::iterator sit;
	IMonitorModule *elm;

	for (sit = targets.begin(); sit != targets.end(); sit++) {
		elm = *sit;
		button = gtk_button_new_with_label (elm->getInfo().c_str());
		gtk_widget_set_size_request(button, 50, 10);
		g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
		gtk_grid_attach (GTK_GRID (grid), button, elm->getX(), elm->getY(), 1, 1);
		butts.push_back(button);
	}
/*	button1 = gtk_button_new_with_label ("Grosse Tata");
	gtk_widget_set_size_request(button1, 300, 10);
	gtk_button_set_label(GTK_BUTTON(button1), "Grosse Tati");
	g_signal_connect (button1, "clicked", G_CALLBACK (print_hello), NULL);
	gtk_grid_attach (GTK_GRID (grid), button1, 0, 0, 1, 1);
	button2 = gtk_button_new_with_label ("Button 2");
	gtk_button_set_label(GTK_BUTTON(button2), "Shit");
	gtk_button_set_label(GTK_BUTTON(button1), "Big Shit");
	g_signal_connect (button2, "clicked", G_CALLBACK (print_hello), NULL);
	gtk_grid_attach (GTK_GRID (grid), button2, 1, 1, 1, 1);
	quit = gtk_button_new_with_label ("Quit");
	g_signal_connect (quit, "clicked", G_CALLBACK (gtk_main_quit), NULL);
	gtk_grid_attach (GTK_GRID (grid), quit, 0, 2, 2, 1);
*/
	gtk_widget_show_all (window);

	gtk_main ();
/*
	blist::iterator bit;
	while (42) {
		usleep(DELAY);
		for (sit = targets.begin(), bit = butts.begin();
				sit != targets.end(), bit != butts.end(); sit++, bit++) {
			elm = *sit;
			button = *bit;
			elm->update();
			g_print(elm->getInfo().c_str());
			g_print("\n");
			gtk_button_set_label(GTK_BUTTON(button), elm->getInfo().c_str());
		}
	}*/
}

GTKDisplay & GTKDisplay::operator=(GTKDisplay const &) {
	return *this;
}

