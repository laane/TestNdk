package fr.laane.android.testndk;

import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;


public class MainActivity extends ActionBarActivity {

    private native int add(int a, int b);
    private native int setArray(int[] array);

    static {
        System.loadLibrary("native");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        int array[] = new int[10];

        for (int i = 0; i < 10; ++i) {
            array[i] = 9;
        }
        for (int i = 0; i < 10; ++i) {
            Log.d("trol", "array[] = " + array[i]);
        }

        setArray(array);

        for (int i = 0; i < 10; ++i) {
            Log.d("trol", "array[] = " + array[i]);
        }


    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
